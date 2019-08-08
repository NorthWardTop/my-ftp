CC=gcc
CFLAGS=-Wall -g
TARGET=my-ftp
OBJS=main.o sysutil.o session.o  \
	ftpproto.o privparent.o str.o	\
	tunable.o parseconf.o
LIBS=-lcrypt -lm

#　将所有的目标文件链接成可执行文件
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)


# 编译找到的第一个依赖文件.c
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -f *.o $(TARGET)

