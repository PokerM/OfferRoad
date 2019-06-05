# 第2章 简单动态字符串
## SDS定义
sdshdr结构
```c
struct sdshdr{
    int len;//已使用长度，不包括'\0'
    int free;//空闲字节数量
    char buf[];//字节数组
};
```
## SDS与C字符串的区别
1. 常数时间获取字符串长度：返回len
2. 杜绝缓冲区溢出：操作前先检查free或者len，缓冲区不够则扩展后再操作
3. 减少修改字符串时带来的内存重分配次数：
    - 空间预分配：小于1MB，直接*2，大于1MB，则+1MB（不包括'\0'）
    - 惰性空间释放：直接修改len和free字段，字符修改后长度变短并不会直接回收空间，而是惰性释放，增加free，在真正有需要的时候，释放未使用空间
4. 二进制安全：不是通过'\0'来确认是否结束，而是通过len
5. 兼容部分C字符串函数：这是保留'\0'的原因

# 第3章 链表
### 双向链表：无环，首节点的前置节点与尾节点的后置节点均为null
### list结构保存首尾两个节点指针以及链表长度信息

# 第4章 字典
## 哈希表
dictht结构
```c
typedef struct dictht{
    dictEntry** table;       //哈希表数组
    unsigned long size;      //哈希表大小
    unsigned long sizemask;  //哈希表大小掩码，用于计算索引值
    unsigned long used;      //哈希表已有节点数量
} dictht;
```
哈希表节点dictEntry
```c
typedef struct dictEntry{
    void* key;              //键
    union{
        void* val;
        uint64_t u64;
        int64_t  s64;
    }v;                     //值,*union根据value的不同类型取出不同引用*
    struct dictEntry *next; //指向下个哈希表节点，链表法解决冲突
} dictEntry;
```
字典
```c
typedef struct dict{
    dictType* type; //类型特定函数
    void* privdata; //私有数据，保存需要传给类型特定函数的参数
    dictht ht[2];   //哈希表，再哈希时使用ht[1]
    int rehashidx;  //没有再哈希时等于-1
} dict;
```
## 哈希算法
Redis计算哈希值和索引值的方法：
```c
hash = dict->type->hashFunction(key);//计算哈希值,redis使用的是MurmurHash2
index = hash & dict->ht[x].sizemask; //与上掩码，计算索引
```
一个好的哈希算法：
- 性能高，算的快
- 相邻数据hash后分布广

## 解决键冲突
链表法

## rehash
哈希表的键值对的数量变化，为保证负载因子维持在合理范围，需要进行重哈希。
rehash步骤：
1. 为ht[1]分配空间，空间大小取决于要执行的操作和ht[0]当前包含的键值对数量(ht[0].used)
    - 如果执行扩展操作，那么ht[1]大小=ht[0].used * 2<sup>n</sup>
    - 如果执行收缩操作，那么ht[1]大小=ht[0].used * 2<sup>n</sup>
2. 将ht[0]的所有键值hash到ht[1]中
3. 释放ht[0]，交换ht[0] ht[1]

当hash表满足下面任意一个条件时，执行rehash
- 服务器目前没有执行BGSAVE或者BGREWRITEAOF命令，并且哈希表的负载因子大于等于1
- 服务器目前正在执行BGSAVE或者BGREWRITEAOF命令，并且哈希表的负载因子大于等于5
- 负载因子小于0.1时执行收缩操作

BGSAVE或者BGREWRITEAOF命令执行时，redis需要创建当前服务器进程的子进程，而大多数操作系统都采用写时复制技术，
所以在子进程执行过程中，服务器会提高执行扩展操作的负载因子，从而避免在子进程存在期间进行哈希表的扩展操作

## 渐进式哈希
扩展或收缩哈希表需要将ht[0]里面的所有键值对rehash到ht[1]中，若键值对数量很大，一次性全部rehash需要花费很长的时间，
redis采用分多次，渐进式rehash，步骤如下：
1. 为ht[1]分配空间，让字典同时持有ht[0]和ht[1]
2. 在字典中维持索引计数器变量rehashidx，并将其设置为0
3. 依次对ht[0]中的键值对rehash到ht[1]中，并维护rehashidx
4. 全部完成ht[0]中的键值对rehash，rehashidx设置为-1

# 第5章 跳跃表
- 实现有序集合键
- 集群节点中用作内部数据结构

## 跳跃表的实现
### 跳跃表的节点
redis.h/zskiplistNode
```c
typedef struct zskiplistNode{
    struct zskiplistNode* backward;     //后退指针
    double score;                       //分值
    robj* obj;                          //成员对象

    //层:
    struct zskiplistLevel{
        struct zskiplistNode* forward;  //前进指针
        unsigned int span;              //跨度
    }level[];                           
} zskiplistNode;
```
# 第6章
整数集合(intset)是集合键的


