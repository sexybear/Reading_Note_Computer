#shell
##编程基础
+ vi/vim 编辑器的命令  vimrc设置
+ 命令基础  100多个命令
+ 基础  高端的网络服务   nfs rsyno inotify  lanmp sersync  ssh  key批量分发管理

##shell脚本简介
shell是一个命令解释器，负责直接与用户对话，把用户的输入解释给操作系统，并处理各种各样的操作系统的输出结果，并在屏幕展示给用户

清空日志的三种方法(主要用于保留文件，清空内容)：
+ echo "">test.log
+ >test.log
+ cat /dev/null >test.log

shell脚本很擅长处理纯文本类型的数据，而linux中几乎所有的配置文件，日志文件都是纯文本类型的文件。

脚本语言的种类：
+ bourne shell(sh,ksh,bash)
+ C shell(csh,tcsh)

shell脚本语言是弱类型语言。

centos 默认的shell是**bash**.

##规范的shell脚本
+ 脚本开头

    >一个规范的shell脚本的第一行会指出哪个程序来执行脚本中的内容。如果脚本的开头不指定解释器，那么就要用对应的解释器来执行脚本。
    
        #！/bin/bash 或者 #！/bin/sh
        #！又称为幻数，内核会根据它来确定用哪个程序来解释脚本中的内容。
+ 注释



