#ifndef __CONNECTOR_H__
#define __CONNECTOR_H__

#include "buffer.h"

class connector
{
public:
	connector(int epoll_fd, int fd, char *ip, void *arg);
	~connector();

	void free();
	
private:
	int m_epoll_fd;
	int m_fd;
	buffer *m_buffer;
	char m_ip[20];
	void *m_arg;
};

#endif