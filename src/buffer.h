#ifndef __BUFFER_H__
#define __BUFFER_H__

class buffer
{
public:
	buffer();
	~buffer();

	const char *begin();
	void append(const char *data, int len);
	void remove(int len);
	int size();
	
private:
	char *m_buffer;
	int m_size;
	int m_max_size;
};

#endif