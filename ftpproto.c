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
#include "str.h"

void handle_child(session_t* sess)
{
	int ret;
	//登录banner
	writen(sess->ctrl_fd, "220 (my-ftp v0.1)\r\n", strlen("220 (my-ftp v0.1)\r\n"));
	while (1) {
		memset(sess->cmdline, 0, sizeof(sess->cmdline));
		memset(sess->cmd, 0, sizeof(sess->cmd));
		memset(sess->arg, 0, sizeof(sess->arg));
		ret = readline(sess->ctrl_fd, sess->cmdline, MAX_CMD_LINE);
		if (ret < 0)
			ERR_EXIT("child read command failed!");
		else if (ret == 0) //客户端断开
			ERR_EXIT("Client disconnected!");
		//解析FTP命令和参数
		str_trim_crlf(sess->cmdline);
		printf("cmd = [%s]\n", sess->cmdline);
		str_split(sess->cmdline, sess->cmd, sess->arg, ' ');
		str_upper(sess->cmd);
		//printf("%s: %s\n", sess->cmd, sess->arg);

	}
}
