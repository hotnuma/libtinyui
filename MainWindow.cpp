#include "MainWindow.h"
#include <CString.h>

MainWindow::MainWindow()
{
    _createWindow();
}

MainWindow::~MainWindow()
{
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

    g_signal_connect(_wnd, "destroy", G_CALLBACK(_onDestroyCB), this);
}

void MainWindow::_onDestroy(GtkWidget*)
{
    //print("destroy");

    bool last = isLastWindow(this);

    setWindowObject(_wnd, nullptr);
    delete this;

    if (last)
        gtk_main_quit();
}


