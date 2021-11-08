#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CWindow.h"

class MainWindow : public CWindow
{
public:

    MainWindow();
    virtual ~MainWindow();

private:

    SMAP1(MainWindow*, void, _onDestroy, GtkWidget*)

    void _createWindow();

};

#endif // MAINWINDOW_H


