#include "MainWindow.h"

#include <print.h>

void MainWindow::_actionOpen(GtkWidget*)
{
    print("clicked");
}

void MainWindow::_actionQuit(GtkWidget*)
{
    gtk_window_close(GTK_WINDOW(_wnd));
}


