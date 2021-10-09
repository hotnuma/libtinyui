#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CWindow.h"

class MainWindow : public CWindow
{
public:

    MainWindow();
    virtual ~MainWindow();

private:

    MAP_SIMPLE(MainWindow*, void, _actionOpen, GtkWidget*)
    MAP_SIMPLE(MainWindow*, void, _actionQuit, GtkWidget*)

    MAP_SIMPLE(MainWindow*, void, _onDestroy, GtkWidget*)

    void _createWindow();
    GtkWidget* _createMenu();
    GtkWidget* _createToolbar();



};

#endif // MAINWINDOW_H


