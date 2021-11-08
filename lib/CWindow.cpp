#include "CWindow.h"

GtkWidget* menuCreateSub(GtkWidget *parent, const char *label)
{
    // File menu
    GtkWidget *menu = gtk_menu_new();
    GtkWidget *item = gtk_menu_item_new_with_label(label);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(parent), item);

    return menu;
}

GtkWidget* menuAppendItem(GtkWidget *parent, const char *label,
                          GCallback func, CWindow *wnd)
{
    GtkWidget *item = gtk_menu_item_new_with_label(label);
    gtk_menu_shell_append(GTK_MENU_SHELL(parent), item);
    g_signal_connect(G_OBJECT(item), "activate", func, wnd);

    return item;
}

GtkToolItem* toolbarAppendItem(GtkWidget *parent, const char *name,
                                      GCallback func, CWindow *wnd)
{
    GtkWidget *img = gtk_image_new_from_icon_name(
        name,
        GTK_ICON_SIZE_SMALL_TOOLBAR
    );

    GtkToolItem *item = gtk_tool_button_new(
        img,
        nullptr
    );

    gtk_toolbar_insert(GTK_TOOLBAR(parent), item, -1);
    g_signal_connect(G_OBJECT(item), "clicked", func, wnd);

    return item;
}

void toolbarAppendSeparator(GtkWidget *parent)
{
    GtkToolItem *sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(parent), sep, -1);
}


void notebookAppend(GtkWidget *notebook, const char *title, GtkWidget *page,
                    GCallback func, CWindow *wnd)
{
    // label.
    GtkWidget *label=gtk_label_new(title);

    // button.
    GtkWidget *cross=gtk_label_new(nullptr);
    gtk_label_set_markup(GTK_LABEL(cross), "<span foreground='black'>x</span>");
    GtkWidget *button=gtk_button_new();
    gtk_container_add(GTK_CONTAINER(button), cross);

    GtkWidget *box=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    gtk_box_pack_start(GTK_BOX(box), label, true, true, 0);
    gtk_box_pack_start(GTK_BOX(box), button, false, false, 0);
    gtk_widget_show_all(box);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, box);

    g_signal_connect(button, "clicked", func, wnd);
}

bool isLastWindow(CWindow *wnd)
{
    GList *list = gtk_window_list_toplevels();

    for (GList *i = list; i; i = i->next)
    {
        CWindow *cwnd = (CWindow*) getWindowObject(GTK_WIDGET(i->data));

        if (cwnd && cwnd != wnd)
        {
            return false;
        }
    }

    return true;
}

CWindow::CWindow()
{
}

CWindow::~CWindow()
{
}

void CWindow::showAll()
{
    gtk_widget_show_all(_wnd);
}


