#include "MainWindow.h"
#include <CString.h>

#include <print.h>

MainWindow::MainWindow()
{
    _createWindow();
}

MainWindow::~MainWindow()
{
    print("delete");
}

void MainWindow::_createWindow()
{
    _wnd = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(_wnd), "App Title");
    gtk_window_set_default_size(GTK_WINDOW(_wnd), 400, 300);
    gtk_window_set_position(GTK_WINDOW(_wnd), GTK_WIN_POS_CENTER);
    setWindowObject(_wnd, this);

    _grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(_wnd), _grid);

    GtkWidget *menubar = _createMenu();
    gtk_grid_attach(GTK_GRID(_grid), menubar, 0, _gridrow, 1, 1);
    ++_gridrow;

    _toolbar = _createToolbar();
    gtk_grid_attach(GTK_GRID(_grid), _toolbar, 0, _gridrow, 1, 1);
    ++_gridrow;

    GtkWidget *scrolled_w = gtk_scrolled_window_new(nullptr, nullptr);
    gtk_widget_set_hexpand(scrolled_w, true);
    gtk_widget_set_vexpand(scrolled_w, true);
    gtk_grid_attach(GTK_GRID(_grid), scrolled_w, 0, _gridrow, 1, 1);
    ++_gridrow;

    GtkWidget *view = gtk_text_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_w), view);

    _statusbar = gtk_statusbar_new();
    gtk_grid_attach(GTK_GRID(_grid), _statusbar, 0, _gridrow, 1, 1);
    ++_gridrow;

    g_signal_connect(_wnd, "destroy", G_CALLBACK(_onDestroyCB), this);
}

GtkWidget* MainWindow::_createMenu()
{
    // Menu bar
    GtkWidget *menubar = gtk_menu_bar_new();

    GtkWidget *menu = menuCreateSub(menubar, "File");

    menuAppendItem(menu, "Open...", G_CALLBACK(_actionOpenCB));
    menuAppendItem(menu, "Quit", G_CALLBACK(_actionQuitCB));

    return menubar;
}

GtkWidget* MainWindow::_createToolbar()
{
    GtkWidget *toolbar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

    toolbarAppendItem(toolbar, "gtk-new", G_CALLBACK(_actionOpenCB));
    toolbarAppendItem(toolbar, "gtk-open", G_CALLBACK(_actionOpenCB));
    toolbarAppendItem(toolbar, "gtk-save", G_CALLBACK(_actionOpenCB));
    toolbarAppendSeparator(toolbar);
    toolbarAppendItem(toolbar, "gtk-quit", G_CALLBACK(_actionOpenCB));

    return toolbar;
}

void MainWindow::_onDestroy(GtkWidget*)
{
    bool quit = true;

    GList *list = gtk_window_list_toplevels();

    for (GList *i = list; i; i = i->next)
    {
        CWindow *window = (CWindow*) getWindowObject(GTK_WIDGET(i->data));

        if (window && window != this)
        {
            quit = false;
            break;
        }
    }

    setWindowObject(_wnd, nullptr);
    delete this;

    if (quit)
        gtk_main_quit();

    print("destroy");
}


