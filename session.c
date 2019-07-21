/*
 * @Author: northward
 * @Github: https://github.com/northwardtop
 * @Date: 2019-07-21 10:00:37
 * @LastEditors: northward
 * @LastEditTime: 2019-07-21 21:02:00
 * @Description: 每个链接会话相关
 */

#include "common.h"
#include "session.h"
#include "ftpproto.h"
#include "privparent.h"

/**
 * @description: 主进程创建的子进程执行session
 * session再创建服务进程/孙子进程,
 * 子进程用于程序内部通信/nobody进程 
 * @param {type} 
 * @return: 
 */
void begin_session(session_t *session)
{
	int sp[2];
	pid_t pid;
	int ret;
	struct passwd *pw;

	pw = getpwnam("nobody");
	if (pw == NULL) 
		ERR_EXIT("get passwd name failed!");
	//将父进程切换为nobody进程,先设置组,再设置用户
	if (setgid(pw->pw_gid) < 0)
		ERR_EXIT("set group id failed!");
	if (setuid(pw->pw_uid) < 0)
		ERR_EXIT("set user id failed!");

	ret = socketpair(PF_UNIX, SOCK_STREAM, 0, sp);
	if (ret < 0) 
		ERR_EXIT("socket pair create failed!");
	
	pid = fork();
	if (pid < 0) 
		ERR_EXIT("session fork");
	else if (pid ==0) { //子进程/服务进程
		close(sp[0]); //使用sp1和父进程通信
		session->child_fd = sp[1];
		handle_child(session);
	} else { //父进程/nobody进程
		close(sp[1]); //使用sp0和子进程通信
		session->parent_fd = sp[0];
		handle_parent(session);
	}
}