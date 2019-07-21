/*
 * @Author: northward
 * @Github: https://github.com/northwardtop
 * @Date: 2019-07-21 10:36:06
 * @LastEditors: northward
 * @LastEditTime: 2019-07-21 23:23:33
 * @Description: 用于处理服务进程,与外界通信
 */


#include "ftpproto.h"
#include "session.h"
#include "sysutil.h"

void handle_child(session_t* sess)
{
	while (1) {
		writen(sess->ctrl_fd, "220 (my-ftp v0.1)\r\n", strlen("220 (my-ftp v0.1)\r\n"));
		memset(sess->cmdline, 0, sizeof(sess->cmdline));
		memset(sess->cmd, 0, sizeof(sess->cmd));
		memset(sess->arg, 0, sizeof(sess->arg));
		readline(sess->ctrl_fd, sess->cmdline, MAX_CMD_LINE);
		//解析命令和参数
		
	}
	
}
