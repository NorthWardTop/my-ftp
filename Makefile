CC=gcc
CFLAGS=-Wall -g
TARGET=my-ftp
OBJS=main.o sysutil.o session.o ftpproto.o privparent.o
LIBS=-lcrypt

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -f *.o $(TARGET)

