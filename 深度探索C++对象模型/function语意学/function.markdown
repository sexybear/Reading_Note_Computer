#深度探索C++对象模型
##Function 语意学
C++支持三种类型的member function：static nonstatic  virtual，每一种类型调用的方式都不相同。

C++的设计准则之一是：nonstatic member function至少必须和一般的nonmember function有相同的效率。

member function被内化为nonmember的形式的转化步骤：

1. 改写函数的signature以安插一个额外的参数到member function中，用以提供一个存取管道，使class object得以调用该函数，该额外参数被称为this指针。
2. 将每一个对nonstatic data member 的存取操作改为经由this指针来存取。
3. 将member function重新写成一个外部函数，对函数名称进行mamgling处理，使它在程序中成为独一无二的语汇

