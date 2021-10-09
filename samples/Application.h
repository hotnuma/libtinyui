#ifndef APPLICATION_H
#define APPLICATION_H

#include <gtk/gtk.h>
#include "libsignal.h"

class Application
{
public:

    Application();

    int run(int argc, char **argv);

private:

    M_CALLBACK(_onActivate, GApplication)
    M_CALLBACK(_onButtonClicked, GtkWidget)

//    static void _onButtonClickedCB(GtkButton *btn, Application *data)
//    {
//        gtk_button_set_label(btn, "Hello World");
//    }

    GtkApplication *_app = nullptr;

};

#endif // APPLICATION_H


