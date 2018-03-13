#ifndef __CLIENT_H__
#define __CLIENT_H__

class client
{
public:
	client();
	~client();

	int start();

private:
	void stop();

public:
	static client *get_instance();

private:
	static void signal_handler_t(int signum);

private:
	void do_tcp_recv();
	void do_tcp_send();
	void do_udp_recvfrom();
	int tcp_socket_start();
	int udp_socket_start();
	int unix_socket_start();
	int raw_socket_start();
	void event_loop();
	
private:
	bool m_flag;
	int m_epoll_fd;
	int m_tcp_fd;
	int m_udp_fd;
	int m_unix_fd;
	int m_raw_fd;
	static client *g_client;
};

#endif