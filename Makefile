CC=gcc
CFLAGS=-Wall -g
TARGET=my-ftp
OBJS=main.o sysutil.o session.o  \
	ftpproto.o privparent.o str.o	\
	tunable.o parseconf.o
LIBS=-lcrypt -lm

$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -f *.o $(TARGET)

