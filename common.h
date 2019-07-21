/*
 * @Author: northward
 * @Github: https://github.com/northwardtop
 * @Date: 2019-07-20 22:47:02
 * @LastEditors: northward
 * @LastEditTime: 2019-07-21 11:10:18
 * @Description: 公共系统头文件和一些公共宏
 */

#ifndef _COMMON_H_
#define _COMMON_H_

#include <arpa/inet.h>
#include <crypt.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/capability.h>
#include <netdb.h> 
#include <netinet/in.h>
#include <pwd.h>
#include <shadow.h>
#include <signal.h>
#include <sys/sendfile.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <dirent.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_EXIT(m)                                                            \
  do {                                                                         \
    perror(m);                                                                 \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

#define MAX_CMD_LINE 1024
#define MAX_CMD 32
#define MAX_ARG 1024
#define ICEFTP_CONF "iceftpd.conf"

#endif /* _COMMON_H_ */
