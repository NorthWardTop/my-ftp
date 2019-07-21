/*
 * @Author: northward
 * @Github: https://github.com/northwardtop
 * @Date: 2019-07-20 22:47:12
 * @LastEditors: northward
 * @LastEditTime: 2019-07-21 23:20:43
 * @Description: 主控程序
 */

#include "common.h"
#include "sysutil.h"
#include "session.h"

int main(int argc, char const *argv[])
{

	if (getuid() != 0)
		ERR_EXIT("my-ftp: must be started as root!");
	
	session_t sess = {
		//连接控制
		.ctrl_fd = -1,
		.cmdline = "\0",
		.cmd = "\0",
		.arg = "\0",
		//进程间通信
		.parent_fd = -1,
		.child_fd = -1,
	};
	int conn;
	int pid;
	int listenfd = tcp_server(NULL, 5888);
	while (1) {
		conn = accept_timeout(listenfd, NULL, 0);
		if (conn < 0)
			ERR_EXIT("accept timeout");
		//每进来一个连接就fork一个进程(nobody),
		//进入session后进行fork一个子进程作为外通信进程
		pid = fork();
		if (pid == 0) { //子进程不需要监听连接,关闭
			close(listenfd);
			sess.ctrl_fd = conn;
			begin_session(&sess); //
		} else //父进程不需要连接句柄,关闭
			close(conn);

	}

	return 0;
}
