#if 0

GtkWidget* menuCreateSub(GtkWidget *parent, const char *label);
GtkWidget* menuAppendItem(GtkWidget *parent, const char *label, GCallback func);
GtkToolItem* toolbarAppendItem(GtkWidget *parent, const char *name, GCallback func);
void toolbarAppendSeparator(GtkWidget *parent);

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

g_signal_connect(_wnd, "delete-event", G_CALLBACK(_onDeleteEventCB), this);

bool MainWindow::_onDeleteEvent(GtkWidget*, GdkEvent*)
{
    print("delete-event");

    return false;
}

void MainWindow::_onButtonClicked(GtkWidget *widget)
{
    gtk_button_set_label(GTK_BUTTON(widget), "Hello World");

    CString str = "Status : Ok";

    gtk_statusbar_push(
        GTK_STATUSBAR(_statusbar),
        gtk_statusbar_get_context_id(GTK_STATUSBAR(_statusbar), str),
        str);
}

#endif


