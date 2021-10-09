/*
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along
 *      with this program; if not, write to the Free Software Foundation, Inc.,
 *      51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef LIBSOCKET_H
#define LIBSOCKET_H

#include <glib.h>

G_BEGIN_DECLS

int socket_fd_open_unix(const char *filepath);
int socket_fd_connect_unix(const char *filepath);
int socket_fd_close(int sock);

int socket_fd_gets(int sock, char *buf, int len);
int socket_fd_write_all(int sock, const char *buf, int len = -1);

G_END_DECLS

#endif // LIBSOCKET_H


