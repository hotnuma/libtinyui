#include "MainWindow.h"

int main(int argc, char **argv)

{
    gtk_init(&argc, &argv);

    MainWindow *wnd1 = new MainWindow();
    wnd1->showAll();

    gtk_main();

    return 0;
}


