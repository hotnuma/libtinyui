#include "Application.h"

Application::Application()
{
    _app = gtk_application_new("org.hotnuma.sample", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(_app, "activate", G_CALLBACK(_onActivateCB), this);
}

void Application::_onActivate(GApplication *app)
{
    GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(app));
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *menubar = gtk_menu_bar_new();
    gtk_grid_attach(GTK_GRID(grid), menubar, 0, 0, 1, 1);

    GtkWidget *fileMenu = gtk_menu_new();
    GtkWidget *fileMi = gtk_menu_item_new_with_label("File");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(fileMi), fileMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), fileMi);

    GtkWidget *quitMi = gtk_menu_item_new_with_label("Quit");
    gtk_menu_shell_append(GTK_MENU_SHELL(fileMenu), quitMi);

    GtkWidget *btn = gtk_button_new_with_label("Button");
    gtk_grid_attach(GTK_GRID(grid), btn, 0, 1, 1, 1);
    g_signal_connect(btn, "clicked", G_CALLBACK(_onButtonClickedCB), this);

    gtk_widget_show_all(GTK_WIDGET(window));
}

void Application::_onButtonClicked(GtkWidget *btn)
{
    gtk_button_set_label(GTK_BUTTON(btn), "Hello World");
}

int Application::run(int argc, char **argv)
{
    int status = g_application_run(G_APPLICATION(_app), argc, argv);

    g_object_unref(_app);

    return status;
}


