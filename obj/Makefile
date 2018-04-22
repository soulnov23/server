CC = g++
TARGET_LDFLAGS = -L/usr/local/lib -lpthread
OBJ := $(wildcard *.o)

all : $(OBJ)
	$(CC) $^ -o $(TARGET_NAME) $(TARGET_LDFLAGS)
	@cp -f $(TARGET_NAME) ../
	@cp -f $(TARGET_NAME) ../client

.PHONY : clean

clean :
	rm -rf $(TARGET_NAME) *.o *.bak