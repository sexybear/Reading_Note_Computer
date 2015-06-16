#深度探索C++对象模型
##Function 语意学
C++支持三种类型的member function：static nonstatic  virtual，每一种类型调用的方式都不相同。

C++的设计准则之一是：nonstatic member function至少必须和一般的nonmember function有相同的效率。

member function被内化为nonmember的形式的转化步骤：

1. 改写函数的signature以安插一个额外的参数到member function中，用以提供一个存取管道，使class object得以调用该函数，该额外参数被称为this指针。
2. 将每一个对nonstatic data member 的存取操作改为经由this指针来存取。
3. 将member function重新写成一个外部函数，对函数名称进行mamgling处理，使它在程序中成为独一无二的语汇

**virtua function的一般实现模型**

每一个class有一个virtual table，内含该class之中有作用的virtual function的地址，然后每个object有一个vptr,指向virtual table的所在。

为了支持virtual function机制，必须首先能够对于多态对象有某种形式的执行期类型判断法，最直截了
当的但是成本最高的解决办法是把必要的信息加在ptr身上，在这样的策略之下，一个执政含有两项信息：

1. 它所参考到的对象的地址
2. 对象类型的某种编码，或是某个结构（内含某些信息，用以正确决议出z()函数实例）的地址

这个方法带来两个问题,第一，它明显增加了空间负担，即使程序并不适用多态，第二，它打断了与C程序的链接兼容性
