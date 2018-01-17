CC = g++
TARGET_LDFLAGS = -L/usr/local/lib -lpthread
OBJS := $(wildcard *.o)

all : $(OBJS)
	$(CC) $^ -o $(TARGET_NAME) $(TARGET_LDFLAGS)
	@cp -f $(TARGET_NAME) ../
	@cp -f $(TARGET_NAME) ../server_cli

.PHONY : clean

clean :
	rm -rf $(TARGET_NAME) *.o *.bak

