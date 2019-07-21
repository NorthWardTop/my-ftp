#ifndef _SESSION_H_
#define _SESSION_H_

#include "common.h"

typedef struct _session 
{
	//控制连接
	int ctrl_fd;
	char cmdline[MAX_CMD_LINE];
	char cmd[MAX_CMD];
	char arg[MAX_ARG];

	//父子进程通信
	int parent_fd;
	int child_fd;
}session_t;

void begin_session(session_t *session);

#endif 