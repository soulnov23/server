#ifndef _SERVER_H_
#define _SERVER_H_

#include <string>
using namespace std;

class server
{
public:
	server();
	~server();

	int start();

private:
	void stop();

public:
	static server *get_instance();

private:
	static void signal_handler_t(int signum);

private:
	void do_accept();
	void do_tcp_recv(int fd);
	void do_tcp_send(int fd, string data);
	void do_udp_recvfrom();
	int tcp_socket_start();
	int udp_socket_start();
	int unix_socket_start();
	int raw_socket_start();
	void event_loop();
	
private:
	bool m_flag;
	int m_epoll_fd;
	int m_tcp_listen_fd;
	int m_udp_fd;
	int m_unix_fd;
	int m_raw_fd;
	static server *g_server;
};

#endif