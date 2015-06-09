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


    
