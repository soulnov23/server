#include "connector.h"
#include <string.h>
#include <assert.h>
#include <sys/epoll.h>
#include <unistd.h>
#include "common_func.h"

connector::connector(int epoll_fd, int fd, char *ip, void *arg)
{
	m_epoll_fd = epoll_fd;
	m_fd = fd;
	m_buffer = new buffer;
	assert(m_buffer != NULL);
	strcpy(m_ip, ip);
	m_arg = arg;
}

connector::~connector()
{
	free();
}

void connector::free()
{
	if (-1 == epoll_ctl(m_epoll_fd, EPOLL_CTL_DEL, m_fd, NULL))
	{
		PRINTF_ERROR("epoll_ctl(%d, EPOLL_CTL_DEL, %d) error", m_epoll_fd, m_fd);
	}
	close(m_fd);
	m_fd = -1;
	if (NULL != m_buffer)
	{
		delete m_buffer;	
		m_buffer = NULL;
	}
	memset(m_ip, 0, 20);
	m_arg = NULL;
}

