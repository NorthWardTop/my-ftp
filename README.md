#iceftpd
小型的ftp服务器，运行平台为Linux。  
如果运行不成功，查看/etc/hosts(Ubuntu为/etc/hostname)文件的信息，看主机名对应的ip地址对不对，如果不对，修改为自己主机的ip就行了。

## 主控程序模块
main.c


## 公共头文件
common.h
1. 存放系统头文件包含
2. 一些公共的宏


## 系统工具模块
sysutil.c sysutil.h
1. 获取本地ip地址
2. 设置为非阻塞
3. 设置为阻塞
4. 读/写超时
5. 接受连接/连接超时函数
6. 


## 会话管理模块
session.c session.h
使用会话对象, 对一个新连接进行处理
1. 启动会话: 父进程用于nobody内部服务
	创建子进程用于ftp服务进程


## nobody内部进程
privparent.c privparent.h



## ftp服务进程
ftpproto.c ftpproto.h


