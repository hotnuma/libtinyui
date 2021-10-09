#include "CSingleInstance.h"

#include <sys/stat.h>
#include <unistd.h>

bool _check_socket_permissions(const char *filepath)
{
    struct stat socket_stat;

    if (lstat(filepath, &socket_stat) == 0
        && socket_stat.st_uid != getuid())
    {
        return false;
    }

    return true;
}

void _remove_socket_link_full(const char *filepath)
{
    char real_path[512];
    real_path[0] = '\0';

    // readlink should return something like "/tmp/app_socket.499602d2".

    int len = readlink(filepath, real_path, sizeof(real_path) - 1);

    if ((int) len > 0)
    {
        real_path[len] = '\0';
        unlink(real_path);
    }

    unlink(filepath);
}

CSingleInstance::CSingleInstance()
{
}

CSingleInstance::~CSingleInstance()
{
    close();
}

/* Returns the created socket, -1 if an error occurred or -2 if another socket exists and files
 * were sent to it. */
bool CSingleInstance::open(const char *socket_path, GIOFunc func)
{
    if (_sock > -1)
        close();

    // check whether the real user id is the same as this of the socket file.
    if (!_check_socket_permissions(socket_path))
        return false;

    _isfirst = false;

    if (_file_name == nullptr)
        _file_name = strdup(socket_path);

    _sock = socket_fd_connect_unix(_file_name);

    if (_sock < 0)
    {
        // first instance.

        _remove_socket_link_full(_file_name);

        _sock = socket_fd_open_unix(_file_name);

        if (_sock < 0)
            return false;

        _isfirst = true;

        _iochannel = g_io_channel_unix_new(_sock);
        _watch = g_io_add_watch(
            _iochannel,
            (GIOCondition) (G_IO_IN | G_IO_PRI | G_IO_ERR),
            func,
            nullptr);
    }

    return true;
}

int CSingleInstance::close()
{
    if (_watch > 0)
    {
        g_source_remove(_watch);

        _watch = 0;
    }

    if (_iochannel)
    {
        g_io_channel_shutdown(_iochannel, false, nullptr);
        g_io_channel_unref(_iochannel);

        _iochannel = nullptr;
    }

    if (_sock > -1)
    {
        socket_fd_close(_sock);

        _sock = -1;
    }

    if (_file_name != nullptr)
    {
        if (_isfirst)
            _remove_socket_link_full(_file_name);

        free(_file_name);

        _file_name = nullptr;
    }

    return 0;
}


