/*
 * @Author: northward
 * @Github: https://github.com/northwardtop
 * @Date: 2019-07-21 10:37:43
 * @LastEditors: northward
 * @LastEditTime: 2019-07-21 23:24:38
 * @Description: 用于处理nobody进程,内部进程
 */

#include "session.h"
#include "privparent.h"

void handle_parent(session_t* sess)
{
	while (1)
	{

		//read(sess->parent_fd, buf, &cmd, 1);
		//解析命令,处理命令,内部命令,非ftp协议命令
		

	}
	
}
