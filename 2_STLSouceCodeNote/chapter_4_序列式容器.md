# 第四章 序列式容器
常用的数据结构：array、list、tree、stack、queue、hash table、set、map等

## 4.2 vector
### 4.2.5 内存构造
vector内存的动态增加，不是直接在原空间之后续接新空间，而是以原大小的两倍另外配置一块较大的空间，然后将原内容拷贝过来，然后开始在原内容之后构造新元素，并释放原空间。所以一旦空间重新配置，指向原vector的迭代器就失效了。

## 4.3 list
### 4.3.2 list的节点
```c++
template<class T>
struct __list_node{//双向链表
    typedef void* void_pointer;
    void_pointer  prev;
    void_pointer  next;
    T             data;
}
```

## 4.4 deque
### 4.4.1 deque概述
deque与vector差异：一、deque允许常数时间内对头端进行元素的插入或移除操作；二、deque没有容量概念，因为它动态地以分段连续空间组合而成。
