#include "CWindow.h"

CWindow::CWindow()
{
}

CWindow::~CWindow()
{
}

GtkWidget* CWindow::menuCreateSub(GtkWidget *parent, const char *label)
{
    // File menu
    GtkWidget *menu = gtk_menu_new();
    GtkWidget *item = gtk_menu_item_new_with_label(label);
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(item), menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(parent), item);

    return menu;
}

GtkWidget* CWindow::menuAppendItem(GtkWidget *parent, const char *label,
                                   GCallback func)
{
    GtkWidget *item = gtk_menu_item_new_with_label(label);
    gtk_menu_shell_append(GTK_MENU_SHELL(parent), item);
    g_signal_connect(G_OBJECT(item), "activate", func, this);

    return item;
}

GtkToolItem* CWindow::toolbarAppendItem(GtkWidget *parent, const char *name,
                                      GCallback func)
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
    g_signal_connect(G_OBJECT(item), "clicked", func, this);

    return item;
}

void CWindow::toolbarAppendSeparator(GtkWidget *parent)
{
    GtkToolItem *sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(parent), sep, -1);
}

void CWindow::showAll()
{
    gtk_widget_show_all(_wnd);
}


