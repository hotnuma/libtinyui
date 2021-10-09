#if 0

/*
 * Socket setup and messages handling.
 * The socket allows detection and messages to be sent to the first running instance of Geany.
 * Only the first instance loads session files at startup, and opens files from the command-line.
 */

/*
 * Little dev doc:
 * Each command which is sent between two instances (see send_open_command and
 * socket_lock_input_cb) should have the following scheme:
 * command name\n
 * data\n
 * data\n
 * ...
 * .\n
 * The first thing should be the command name followed by the data belonging to the command and
 * to mark the end of data send a single '.'. Each message should be ended with \n.
 * The command window is only available on Windows and takes no additional data, instead it
 * writes back a Windows handle (HWND) for the main window to set it to the foreground (focus).
 *
 * At the moment the commands window, doclist, open, openro, line and column are available.
 *
 * About the socket files on Unix-like systems:
 * Geany creates a socket in /tmp (or any other directory returned by g_get_tmp_dir()) and
 * a symlink in the current configuration to the created socket file. The symlink is named
 * geany_socket_<hostname>_<displayname> (displayname is the name of the active X display).
 * If the socket file cannot be created in the temporary directory, Geany creates the socket file
 * directly in the configuration directory as a fallback.
 *
 */

#define SOCKET_IS_VALID(s) ((s) >= 0)
#define INVALID_SOCKET (-1)

MAP_DOUBLE(MainWindow*, bool, _onDeleteEvent, GtkWidget*, GdkEvent*)

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


