#ifndef __COMMON_FUNC_H__
#define __COMMON_FUNC_H__

#include <stdio.h>
#include <errno.h>
#include <string.h>

/*
#define PRINTF(format, ...) \
		printf("%s : %s : %d"format"%s", __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__, strerror(errno))
*/
#define PRINTF_DEBUG(format, ...) \
		printf("[DEBUG]%s:%d: %s():"format"\n", __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define PRINTF_ERROR(format, ...) \
		printf("[ERROR]%s:%d: %s():%s\n"format"\n", __FILE__, __LINE__, __FUNCTION__, strerror(errno), ##__VA_ARGS__)

int make_socket_nonblocking(int fd);

int make_socket_reuseaddr(int fd);

int make_socket_tcpnodelay(int fd);

int set_socket_rcvbuf(int fd, int bufsize);

int set_socket_sndbuf(int fd, int bufsize);

#endif