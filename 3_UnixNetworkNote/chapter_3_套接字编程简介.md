# 第3章 套接字编程简介

## 3.1 概述
- 套接字地址结构
- 值-结果参数概念
- 地址转换函数
- 网络套接字读写函数

## 3.2 套接字地址结构
### 3.2.1 IPv4套接字地址结构
```c
struct in_addr{
    in_addr_t s_addr;//32-bit的IPv4地址，此处将单独地址字段定义为一个结构体是有历史原因的。早期版本为多种结构的union，允许访问32bit的IPv4所有4个字节，这在将地址划分为ABC三类（现采用无类地址）的时期，便于获得地址中适当的字节。
};
struct socketaddr_in{
    uint8_t         sin_len;     //不在标准中，不一定有，但其简化了可变长地址结构的处理
    sa_family_t     sin_family;  //AF_INET:IPv4
                                 //AF_INET6:IPv6
                                 //AF_LOCAL:Unix域协议
                                 //AF_ROUTE:路由套接字
                                 //AF_KEY:密钥套接字
    in_port_t       sin_port;    //16-bit TCP or UDP port number
    struct in_addr  sin_addr;    //32-bit IPv4 address
    char            sin_zero[8]; //unused
}
```
一般性说明：
- 至少16个字节：sin_family(1),sin_port(2),sin_addr(4),sin_zero(1*8),该结构体4字节对齐，则没有sin_len也**至少为16个字节**
- IPv4地址和端口号在套接字地址结构中总是以**网络字节序**来存储（因为其需要用在主机间通信）
- sin_zero字段未使用，但几乎所有实现都增加了该字段，在填写套接字地址结构时置0
- 套接字地址结构仅在主机内使用，结构本身不在主机间传递。

## 3.2.2 通用套接字地址结构
通用套接字地址结构用于在函数以指针形式传参时，以所支持的任何协议族的套接字结构。在ANSI C之后采用 void* 通用指针类，所以感觉就没什么用。

## 3.2.3 IPv6套接字地址结构
```c
struct in6_addr{
    unit8_t s6_addr[16];//128-bit的IPv6地址
};
struct socketaddr_in6{
    uint8_t         sin6_len;      //不在标准中，不一定有，但其简化了可变长地址结构的处理
    sa_family_t     sin6_family;   //AF_INET:IPv4
                                   //AF_INET6:IPv6
                                   //AF_LOCAL:Unix域协议
                                   //AF_ROUTE:路由套接字
                                   //AF_KEY:密钥套接字
    in_port_t       sin6_port;     //16-bit TCP or UDP port number
    uint32_t        sin_flowinfo;  //流标
    struct in6_addr sin6_addr;     //128-bit IPv6 address
    uint32_t        sin6_scope_id; //
}
```

一般性说明：
- 若系统支持套接字的长度字段，那么sin6_len常值必须定义
- 若sockaddr_in6结构本身是64位对齐，那么128位的sin6_addr字段也是64位对齐（没搞懂为什么sockaddr_in6结构可能存在64位对齐，最大的不过32-bit）

## 3.2.5 套接字地址结构比较
IPv4 | IPv6 | Unix | 数据链路 | 存储
----- | ------- | ------ | ------- | ---------
len &#124; AF_INET| len &#124; AF_INET6| len &#124; AF_LOCAL| len &#124; AF_LINK| len &#124; AF_*XXX*
16位端口号 | 16位端口号 | 路径名 | 接口索引 | 
32位IPv4地址 | 32位流标 | | |
(未用)| 128位IPv6地址 | | |
||32位范围ID|

# 3.3 值-结果参数
当往套接字函数传递一个套接字地址结构时，结构总是以指针的形式传递。该结构的长度的传递方式取决于结构的传递方向：从内核到进程还是从进程到内核。
1. 从进程到内核传递套接字的函数：bind、connect和sendto（进程主动发起）。结构长度的传递方式为**值传递**。
2. 从内核到进程传递套接字的函数：accept、recvfrom、getsockname和getpeername（从内核的系统调用中取数据）。结构长度的传递方式为**指针传递**。
采用指针传递的原因：函数调用时，结构长度为一个值（value），使内核在写该结构时不越界；当函数返回时，结构长度又是一个结果（result），它告诉进程内核在该结构中写了多少信息。

# 3.4 字节排序函数
小端字节序（little-endian):低序字节存在起始地址

大端字节序（big-endian):高序字节存在起始地址

主机字节序：给定系统的所用的字节序

网际协议使用**大端字节序**来传输字节

主机字节序和网络字节序转换函数
```c
#include <netinet/in.h>
uint16_t htons(uint16_t host16bitvalue);//主机字节序转网络字节序（short）
uint32_t htonl(uint32_t host32bitvalue);//主机字节序转网络字节序（long）
uint16_t ntohs(uint16_t net16bitvalue);//网络字节序转主机字节序（short）
uint32_t ntohl(uint32_t net32bitvalue);//网络字节序转主机字节序（long）
```
# 3.5 字节操纵函数
```c 
#include <string.h>
void bzero(void *dest, size_t nbytes);//将目标字节串的指定数目字节置为0
void bcopy(const void *src, void *dest, size_t nbytes);//复制字节
void bcmp(const void* ptr1, const void* ptr2, size_t nbytes);//比较字节
void* memset(void* dest, int c, size_t len);//指定字节设定为c，其返回值为void*
void* memcpy(void* dest, void* src, size_t nbytes);//复制字节，与bcopy参数顺序不同
int memcmp(const void* ptr1, const void *ptr2, size_t nbytes);//比较字节
```
# 3.6 地址转换函数
```c
#include <arpa/inet.h>
int inet_aton(const char* strptr, struct in_addr* addrptr);//ascii to numeric,若字符串有效返回1，否则返回0
int_addr_t inet_addr(const char* strptr);//返回numeric地址，否则INADDR_NONE（该函数已弃用）
char* inet_ntoa(struct in_addr inaddr);//返回点分十进制数串的指针

//下面两个函数对于IPv4和IPv6均适用，一般使用以下两函数
int inet_pton(int family, const char* strptr, void* addrptr);//presentation to numeric(点分十进制转二进制)。成功返回1，输入不是有效表达返回0，出错返回-1
const char* inet_ntop(int family, const void* addrptr, char* strptr, size_t len);//成功返回指向结果的指针，出错返回NULL
```

# 3.9 readn、writen和readline函数
字节流套接字的read和write函数所表现的行为与一般的文件IO不同。字节流套接字的实际输入或者输出的字节数可能比请求的数量少，原因在于：内核中用于套接字的缓冲区可能已达到了极限。为了不让函数返回一个小于请求数目的字节，自行编写函数来进行封装，基本思路就是定义一个计数器，不断地读写，直达计数器的值大于等于设定值。

readline函数是遇到'\n'或者达到maxlen返回。


