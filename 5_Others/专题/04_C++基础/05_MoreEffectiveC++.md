# 01 指针与引用的区别
1. 指针可以为空，而引用不可以
2. 指针可以不初始化，而引用必须初始化
3. 指针可以根据需要指向不同对象，而引用一旦定义，则不能引用别的

# 04 非必要不提供default constructor
凡可以“合理地从无到有生成对象”的classes，则应该拥有default constructor；而那些“必须有某些外来信息才能生成”的对象不应该有default constructor。

# 05 最好不要提供隐式转换函数
防止意外地调用该隐式转换函数，造成错误。大部分时候需要明白调用类型转换函数。string类并不提供隐式地转换为char*的函数，而是显式的c_str()成员函数。

简易的方法是使用explicit。

# 06 区分++和--的前置与后置形式
```c++
int& operator++();//返回自身的引用，效率高，i=0,++i==1
const int operator++(int);//返回临时变量，需要在函数内创建和销毁临时变量，效率低，返回引用是防止i++++这样的语法
```
# 12 区分“抛出一个异常”与“函数传递”或“调用虚函数”之间的差异
1. exception object在被抛出时总是会被复制，如以by value的方式会被复制两次
2. exception object的内置类型不允许转型，如int类型的exception不会被double类型catch块捕捉
3. catch子句以最先吻合策略匹配，而调用函数根据最佳匹配原则

# 13 以by reference 的方式捕捉exception
by value方式存在的问题：
1. 两次复制，效率不高
2. 派生类的exception可以被基类catch块捕捉，但会发生对象切片，派生类部分的内容会被切掉，再被抛出时，只会被认为是基类的exception

by pointer方式存在的问题：
1. 若抛出指针所指对象为局部对象，那么catch块中指针则为空指针
2. 若抛出指针所指对象为heap object，需要根据所指对象是否为heap object来决定是否在catch块中delete掉

by reference方式只会复制一次，而且派生类exception被基类catch块捕捉后再抛出依然不会有切片问题，能够保持对象的多态性质

# 17 考虑使用lazy evaluation：尽可能把事情延后执行
1. 引用计数，写时复制
2. lazy fetching:缓式取出，大对象只取出其必要部分
3. lazy expression evaluation：只有当用到该值才计算。

# 18 分期摊还预期的计算成本
over-eager-evaluation：在被要求之前就先把事情做好

缓存、vector内存增长都是这个原理。

