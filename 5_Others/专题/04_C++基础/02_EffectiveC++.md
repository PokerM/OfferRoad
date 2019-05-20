# 改善程序与设计的55个具体做法
## 一、让自己习惯C++
1. 视C++为一个语言联邦      
- C++总共有四部分：C、C with class、Template C++、 STL。C++高效编程守则现状视情况而定，取决于使用的是C++哪一部分。
2. 尽量以const、enum、inline替换#define
- 对于单纯常量，以 const 或者 enum 替换#define
- 对于形似函数的宏，改为inline函数
3. 尽可能使用const
- 将某些东西定义为const可帮助编译器侦测出错误用法
- 编译器强制实施bitwise constness ，但编写程序时应该使用“概念上的常量性”
- 当 const 和 non-const 成员函数有着实质等价的实现时，令 non-const 函数调用 const 版本可避免重复
4. 确定对象使用前已先被初始化
- 为内置型对象进行手工初始化，因为C++不保证初始化他们
- 构造函数最高使用列表初始化的方法，而不是在构造函数中使用赋值操作。列表中的次序应该和它们在类中的声明次序相同，初始化的次序与**声明**顺序相同
-为免除“跨编译单元之初始化次序”问题，以 local static 对象替换non-local static 对象
## 二、构造/析构/赋值运算
5. 了解C++默默编写并调用了哪些函数
- 编译器可以为 class 创建 **default构造函数**、**copy构造函数**、**copy assignment 操作符**以及**析构函数**
6. 若不想使用编译器自动生成的函数，则要明确拒绝
- 将相应的成员函数声明为private 并且不予实现
7. 为多态基类声明 virtual 析构函数
- polymorphic（多态性质的）base classes 应该声明一个 virtual 析构函数。
- Classes 的设计目的如果不是作为 base classes 使用，或者不是为了具备多态性，就不该声明virtual 析构函数
8. 别让异常逃离析构函数（析构函数是用于资源释放的，需确保其正常运行，而不是被异常打断）
- 析构函数绝对不要吐出异常。如果一个被析构函数调用的函数可能抛出异常，则析构函数应该捕获任何异常，然后吞下他们或者结束程序
- 如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class 应该提供一个普通函数执行该操作，而不是在析构函数中
9. 绝不在构造和析构过程中调用virtual函数
10. 令 operator= 返回一个 reference to *this 
11. 在operator= 中处理“自我赋值”
12. 复制对象时勿忘其每一个成分
- Copying函数应该确保复制“对象内所有成员变量”及“所有base class 成分”
- 不要尝试以某个 copying 函数实现另一个 copying 函数。应该将共同机能放进第三个函数中，并由两个copying 函数共同调用
## 三、资源管理
13. 以对象管理资源
- 为防止资源泄漏，使用 RAII 对象，它们在构造函数中获得并初始化，在析构函数中释放资源
- 两个常被使用的 RAII classes 分别是 tr1::shared_ptr 和 auto_ptr。前者通常是较佳选择，因为其copy行为比较直观。若选择auto_ptr，复制动作会使它（被复制物）指向null。
14. 在资源管理类中小心 copying 行为
- 复制 RAII 对象必须一并复制它所管理的资源，所以资源的 copying 行为决定 RAII 对象的copying 行为
- 常见的 RAII class copying 行为是：抑制copying、施行引用计数法（reference counting）
15. 在资源管理类中提供对原始资源的访问
- APIs 往往要求访问原始资源，所以每一个RAII class 应该提供一个“取得其所管理资源”的方法
- 对原始资源的访问可能经由显式转换或隐式转换。一般而言，显式转换比较安全，隐式转换比较方便  
16. 成对使用new 和 delete 时要采用相同形式
17. 以独立语句将 newed 对象置入智能指针
- 防止在资源创建和资源转换为资源管理对象之间发生异常，导致资源泄漏
## 四、设计与声明
18. 让接口容易被正确使用，不易被误用
- 促进正确使用的方法包括接口的一致性以及与内置类型行为兼容
- 阻止误用的办法包括建立新类型、限制类型上的操作，束缚对象值，以及消除客户的资源管理责任（使用shared_ptr）
- shared_ptr 支持定制型删除器，可防范DLL问题，可被用来自动解除互斥锁
19. 设计 class 犹如设计 type
20. 尽量以常引用传值替换拷贝传值
21. 返回值一般不要返回引用
22. 将成员变量声明为private
23. non-member、non-friend 替换 member 函数（不需要访问 class 成员变量的函数不要设计为member函数）
24. 所有参数皆需要类型转换，则应为non-member函数（例如+*等二元操作符）
25.  
## 五、实现
26. 尽可能延后变量定义式出现的时间
- 当真正需要变量时定义变量，避免不必要的default构造函数
- 尽可能延后变量定义式的出现，可以增加程序的清晰度并改善程序效率
27. 尽量少做转型动作
- C++在c转型的基础之上新增四种转型方式：1、**const_cast**:常量性移除；2、**dynamic_cast**:安全向下转型；3、**reinterpret_cast**：低级转型，实际动作取决于编译器；3、**static_cast**：强迫隐式转换
- 尽量避免转型，在注重效率的代码中避免dynamic_cast 。
- 如果转型是必要的，可以将其隐藏与函数背后，通过调用函数，而不是将转型放进使用者的代码中
- 优先使用C++转型
28. 避免返回handles 指向对象内部成分
- 避免返回handles 指向对象private成分，保持封装性。
29. 努力保护异常安全
- 异常安全性函数的优点：1、**不泄漏任何资源**；2、**不允许数据败坏**；
- TODO
30. 了解inline
- 将大多数inline限制在小型、被频繁调用的函数身上。可使得调试过程和二进制升级更容易，也可使代码膨胀问题最小化
31. 将文件间编译依存关系降到最低
- 支持“编译依存性最小化”的一般构想是：相依存与声明式，不要相依于定义式。基于此构想的两个手段是Handles classes 和 Interface classes
- 程序库头文件应该以“完全且仅有声明式”的形式存在。
## 六、继承和面向对象设计
32. 确定 public 继承出 is-a 的关系
- public 继承意味着is-a。适用于base classes身上的每一件事情一定也适用于 derived classes 身上
33. 避免遮掩继承而来的名称
- derived classes 内的名称会遮掩 base classes 内的名称。勿使用与base classes的同名变量或函数
- 可使用using 声明式来使得base classes的重见天日
34. 区分接口继承和实现继承
- 接口继承只继承函数接口，实现继承会继承base classes 的实现
35. 考虑virtual 函数以外的其他选择
- virtual 函数的替代方案包括 **NVI手法** 和 **Strategy 设计模式**。NVI手法自身是一个特殊形式的*TemplateMethod*设计模式
36. 绝不重新定义继承而来的 non-virtual 函数
- non-virtual 函数由于是静态绑定，则分别通过base classes 和 derived class 指针指向derived object时，其调用的non-virtual 函数是不同的
37. 绝不重新定义继承而来的缺省参数值
- 理由同上，缺省参数值也是静态绑定，会造成二义性
38. 通过 composition 来 model has-a or is-implemented-in-terms-of
- 复合（composition）在应用域意味着has-a，在实现域意味着is-implemented-in-terms-of
39. 明智而审慎地使用private继承
- private 继承意味着is-implemented-in-terms-of。通常比composition优先级低，但当derived class 需要访问protected base class 成员或需要重新定义virtual 函数时，可以使用private 继承
- private 继承在empty base时最优化对象大小，复合会给empty base object分配一个空间
40. 明智而审慎地使用多重继承
- 多重继承比单一继承复杂，可能导致歧义性，以及对virtual继承的需要
- virtual 继承会增加大小、降低速度、初始化复杂度增加等成本。如果virtual class 不带任何成员变量是virtual继承最具有实用价值的情况
- 多重继承的一个正当用途：public继承某个 interface class 和 private 继承某个协助实现的 class 组合 
## 模板与泛型编程
41. 了解隐式接口与编译期多态
- 多态分为编译期多态和运行期多态：编译期多态指的是选用哪个重载函数或者template调用哪个具现化的函数，运行时多态是根据对象调用不同的virtual函数
- class 和 template 都支持多态和接口。class 支持显式接口（基于函数签名）和运行时多态，template支持隐式接口（基于有效表达式）和通过template具现化和函数重载解析发生在编译期的多态
42. 了解typename的双重意义
- 声明template参数时， class 和 typename 可以互换
- 使用typename 标识嵌套从属类型名称，但不得在base class lists 或者member initialization 内作为 base class 修饰符
43. 学习处理模板化基类内的名称
44. 将与参数无关的代码抽离template
44. 运用成员函数模板接受所有兼容类型
- 使用member function template 生成“可接受所有兼容类型”的函数
- 如果使用member templates 用于泛化copy构造或者泛化 assignment 操作，则还需要声明正常的copy 构造函数和copy assignment 操作符
46. 类型转换使用非成员函数
- 编写一个class template时，提供与此template 相关的函数支持所有参数隐式类型转换时，将那些函数定义为class template 内部的 friend 函数 
47. traits classes 表现类型信息（一种规范）
- 五类迭代器：input_iterator output_iterator forward_iterator bidirectional_iterator random_access_iterator
48. 了解元编程
 