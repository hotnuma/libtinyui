#ifndef CSINGLEINSTANCE_H
#define CSINGLEINSTANCE_H

#include "libsocket.h"

bool _check_socket_permissions(const char *filepath);
void _remove_socket_link_full(const char *filepath);

class CSingleInstance
{
public:

    CSingleInstance();
    virtual ~CSingleInstance();

    bool open(const char *socket_path, GIOFunc func);
    bool isFirst() {return _isfirst;}
    int sock() {return _sock;}

    int close();

private:

    char *_file_name = nullptr;
    bool _isfirst = false;
    int _sock = -1;

    GIOChannel *_iochannel = nullptr;
    uint _watch = 0;

};

#endif // CSINGLEINSTANCE_H


