#Linux编程笔记

**C的基本类型**就是：整数  小数  unsigned  signed   运算符号 类型都比较简单，所有的劝你性能类型都是使用typedef来重新定义。见到新的类型，要懂它的C的原型。

**类型重定义的好处**
+ 维护方便
+ 便于移植
+ 容易理解


##映射虚拟内存
linux整个内存技术采用的是虚拟技术。

没有任何额外维护数据的内存分配：
+ mmap(分配)
+ unmap(释放)

mmap函数中的length  = 4k（内存/4k  + 1）

**函数说明**

void *mmap(void *start,size_t length,int prot,int flags,int fd,offset_t off);

flag指映射方式，包括：
+ 内存映射：匿名映射
+ 文件映射：映射到某个文件

    >只有文件映射最后两个参数有效，映射的开始位置必须是pagesize的倍数。
    >MAP_ANONYMOUS（内存或文件映射的标志） MAP_SHARED  MAP_PRIVATE （后面两个二选一）
    
数组和指针主要的区别：一个是变量 一个是常量

**总结**
选择什么样的内存管理方法：
+ 智能指针（指针池）
+ STL
+ new
+ malloc(小而多的数据)
+ brk/sbrk(同类型的大块数据，可以根据需要动态的移动指针)
+ mmap/munmap(控制内存的访问方式/内存直接使用文件映射/控制内存的共享)

    >速度最快，效率最高的是最后两个
    
##编程工具与动态库
###gcc

编译过程中，自动调用连接器（ld）。
    
    > -o 
    > -O -O0 -O1 -O2 -O3 编译优化
    > -g -g0 -g1 -g2 -g3 产生调试信息
    > -W all error 
    > -Wall 显示所有警告
    > -Werror 把警告当错误
    > -w 关闭警告
    > -c 只编译不连接
    > -E 预编译
    > -S 汇编
    > -D 在命令行定义宏
    
定义宏的两种方式：在代码中定义宏，在命令行中定义宏

编译器主题选项：

1. 静态库编译（static ar工具 ）

    >编译成目标文件(static  可选)
    >
    >归档成静态库（ar工具   nm工具）
    
        ar -r 静态库文件  被归档的文件
        
        nm查看函数符号表
        
        nm  静态库  或者  动态库 或者目标文件  或者可执行文件  
2. 动态库编译


###make
###gdb
###其他工具
###动态库
**什么是动态库（共享库）**

动态库是可以执行的，静态库不能够执行。但动态库没有main,不能独立执行。动态库不会连接成程序的一部分，程序执行的时候，必须需要动态库文件。

**工具**

+ ldd   可以查看程序需哟啊调用的动态库
+ ldd   只能查看可执行文件
+ readelf -h  查看执行程序头
+ nm    查看库中的函数符号

**动态库的编译**

1. 编译

        >-c -f pic(可选)(位置无关代码)
2. 连接

        >-shared
        
**使用动态库**

gcc 代码 动态库文件名

gcc 代码 -l库名 -L动态库所在路径 

**动态库的加载**

1. 找到动态库
2. 加载动态库的内存
3. 映射到用户的内存空间

**系统对动态库查找规则**

1. /lib
2. /usr/lib
3. 到环境变量LD_LIBRARY_PATH指定的路径中找

**缓冲机制**

把上面提到的三种路径加载到缓存中

/sbin/ldconfig -v  刷新缓冲中so的搜索数据

---------------------------
**什么事库**

函数等代码封装的二进制已经编译的归档文件

**采用库的方式管理代码的优点**

容易组织代码  复用   保护代码版权

**静态库的静态的含义**

编译好的程序运行的时候不依赖库

库作为程序的一部分编译链接

**静态库本质**

就是目标文件集合

**-static 可选**


**库的规范与约定**

所有的库有一套命名规则  lib库名.a.主版本号.副版本号.批号

库使用规则：  -l 库名       -L  库所在目录



    
