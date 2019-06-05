### 优点：
1. 单例模式中，活动的单例只有一个实例。
2. 单例模式具有一定的伸缩性，类自己控制实例化进程，类在改变实例化进程上有相应的伸缩性
3. 提供了对唯一实例的受控访问
4. 由于系统内存中只存在一个对象，可以节约系统资源
5. 允许可变数量的实例
6. 避免共享资源的多重占用

### 缺点：
1. 不适用变化的对象
2. 没有抽象层，很难扩展
3. 单例类职责过重，一定程度上违背来了“单一职责原则”
4. 滥用单例将带来负面问题

### 适用场景：
单例模式只允许创建一个对象，可以节约内存，加快对象访问速度，因此适合当对象需要被公用的场景。
1. 需要频繁实例化然后销毁且不变化的对象
2. 创建对象时消耗时间或者资源过多，但对象又经常被使用
3. 有状态的工具类对象

### 应用举例：
1. 外部资源：打印机
2. 内部资源：系统属性管理对象
3. Windows的任务管理器
4. Windows的回收站
5. 网站计数器
6. 应用程序的日志应用
7. Web应用的配置对象的读取
8. 数据库连接池
9. 多线程的线程池
10. HttpApplication

```c++
//简单singleton实现，线程不安全:若两个线程同时首次调用getInstance()，同时检测ptr为NULL，将会实例化两次。
class singleton{
protected:
    singleton(){};//默认构造函数定义为protected，防止类外实例化
private:
    static singleton* ptr;
public:
    static singleton* getInstance();
};
singleton* singleton::ptr = NULL;
singleton* singleton::getInstance(){
    if(ptr == NULL){
        ptr = new singleton(); 
    }
    return ptr;
}

//懒汉与饿汉
//懒汉：不到万不得已不实例化。只有在调用时才实例化。（上述则为懒汉）
//饿汉：类定义时就进行实例化。

//线程安全的懒汉
//实现：加锁
class singleton{
protected:
    singleton(){
        pthread_mutex_init(&m_mutex,NULL);//互斥锁初始化，
    };
private:
    static singleton* ptr;
public:
    static pthread_mutex_t m_mutex;
    static singleton* getInstance();
    ~singleton(){
        //pthread_mutex_destroy(&m_mutex);//无需调用,m_mutex为静态分配，若使用malloc动态分配内存才调用才函数
    }
};
pthread_mutex_t singleton::m_mutex;
singleton* singleton::ptr = NULL;
singleton* singleton::getInstance(){
    if(ptr == NULL){//当ptr != NULL时，无需加锁，提高效率
        pthread_mutex_lock(&m_mutex);//加锁是比较耗时的操作
        if(ptr == NULL){//确保ptr未被实例化
            ptr = new singleton(); 
        }
        pthread_mutex_unlock(&m_mutex);
    }
    return ptr;
}

//饿汉实现，实现简单，不用加锁，线程安全
class singleton{
protected:
    singleton(){};//默认构造函数定义为protected，防止类外实例化
private:
    static singleton* ptr;
public:
    static singleton* getInstance();
};
singleton* singleton::ptr = new singleton;//ptr为类中的静态对象，能够调用protected的构造函数
singleton* singleton::getInstance(){
    return ptr;
};
int main(){
    static singleton* p = singleton::getInstance();
    return 0;
}
```