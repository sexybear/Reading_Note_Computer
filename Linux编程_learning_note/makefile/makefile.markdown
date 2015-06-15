#linux 编程笔记
##makefile
make 命令行的使用
+ make -f make 脚本文件 目标名

###目标的划分
>目标之间产生依赖调用

      compile:
        gcc -c -fpic input.c
        gcc -c -fpic primer.c
      lnk:compile
        gcc -shared -olibdemo.so input.o primer.o
      demo:lnk compile
        gcc demo.c -ldemo -L. -omain
      clean:
        rm -f \*.o \*.so

###默认规则
1. 不指定目标，一般执行第一个目标
2. 不指定make文件，默认文件是makefile 或 Makefile（两个同时有的话，小写的优先）

###目标的调用规则(make把目标当成文件)
>make执行目标：
>
>搜索与目标相同的文件，如果文件存在，则判定日期，如果日期最新，则停止编译，
输出提示，如果日期不是最新的，则进行执行

    比较：当前目标和依赖目标

>建议：把每个编译结果作为一个目标，并且把编译结果作为目标名

>潜规则(**不建议**)： .c目标与.o目标  查找.o目标，目标不存在，就把.o替换成.c，如果.c存在，实施潜规则:直接调用gcc把.c执行成.o

>变量：可以在makefile中定义变量，变量名可以大写也可以小写，其实就是简单的替换

    变量名=值 值
    $变量名 $值

>伪目标：不把目标作为文件处理的目标称为伪目标，即使代码没变，也依然会执行

##环境变量
访问环境变量的方式

1. 直接使用main

  >命令行参数argv与环境行arge都是字符串数组，**约定：**最后一个字符串是NULL/0


      int main(int args,char **argv,char *arge)
      {
        while(*arge)
        {
          printf("%s\n",*arge);
          arge++;
        }
      }

2. 
