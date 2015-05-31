数值积分
===


Cotes.cpp
---

- [x] simpsons 辛普森
- [x] compound_trapezoid 复化梯形
- [x] compound_simpsons 复化辛普森
- [x] cotes 柯特斯
- [ ] 积分余项

Romber.cpp
---

- [x] recurrence_trapezoidal 
- [ ] Romber
- [  ] 积分余项

Gauss.cpp
---

- [x] 两点三点高斯公式
- [  ] 积分余项

简单编程，如果发现存在错误请肆意issue
n的值很小因此暂时没有必要在循环中优化计算结果

另外，余项没有计算。

a , b , h 分别为积分下限，积分上限，步长。map <double, double> f 用来存储函数f(x)的值
使用之前需要先初始化，override `init()`
