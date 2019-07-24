#include <iostream>
#include <cstring>

using namespace std;

/*
c语言字符串处理函数：
1.strcat:字符串拼接
2.stcchr:查找字符char * strchr ( const char *, int ); 
                    pch=strchr(str,'s');
                    while (pch!=NULL)
                    {
                        printf ("found at %d\n",pch-str+1);
                        pch=strchr(pch+1,'s');
                    }
3.strcmp:字符串比较：相等返回0，第一个不同字符更小返回负数，第一个不同的字符更大返回正数
4.strcpy:会复制'\0'.char * strcpy ( char * destination, const char * source );
5.strerror://将错误码转为字符串
            pFile = fopen ("unexist.ent","r");
            if (pFile == NULL)
                printf ("Error opening file unexist.ent: %s\n",strerror(errno));//Error opening file unexist.ent: No such file or directory
            return 0;
6.strlen:返回长度，不包括'\0'
7.strncat:拼接指定长度的字符串
8.strncmp
9.strncpy:复制指定长度，保留大于该长度后的部分
10.strpbrk: char str[] = "This is a sample string";
            char key[] = "aeiou";
            char * pch;
            printf ("Vowels in '%s': ",str);
            pch = strpbrk (str, key);
            while (pch != NULL)
            {
                printf ("%c " , *pch);
                pch = strpbrk (pch+1,key);
            }
            //Vowels in 'This is a sample string': i i a a e i
11.strrchr:查找字符最后一次出现位置
12.strstr:查找字符串，返回查找到的位置的指针，可以和strncpy组合，完成查找替换功能
            char str[] ="This is a simple string";
            char * pch;
            pch = strstr (str,"simple");
            strncpy (pch,"sample",6);
13.strtok:字符串分割
            pch = strtok (str," ,.-");
            while (pch != NULL)
            {
                printf ("%s\n",pch);
                pch = strtok (NULL, " ,.-");
            }
*/

class MyString ;
istream& operator>>(istream& is, const MyString& str); //输入运算符重载
ostream& operator<<(ostream& os, const MyString& str); //输出运算符重载
MyString operator + (const MyString&, const MyString&);
bool operator==(const MyString&, const MyString&);
class MyString{
public:
    MyString(){ch = NULL;};
    MyString(string str);
    MyString(const char* str);           //构造函数
    MyString(const MyString& str);      //拷贝构造函数，注意为const引用传值
    MyString(MyString&& str);
    MyString& operator = (const MyString& str); //赋值操作符重载
    MyString& operator = (MyString&& str);

    friend istream& operator>>(istream& is, const MyString& str); //输入运算符重载
    friend ostream& operator<<(ostream& os, const MyString& str); //输出运算符重载
    friend MyString operator+(const MyString&, const MyString&);
    friend bool operator==(const MyString&, const MyString&);

    int size() const {return strlen(ch);} //返回字符串长度
    int compare(const MyString&);
    MyString& operator += (const MyString& str);//+运算符重载
    char operator[](int n){
        if(n >= strlen(ch) || n<0)throw -1;
        return ch[n];
    }
    ~MyString(){if(ch != NULL)delete ch;}
    char* ch;
};

MyString::MyString(const char* str){
    cout<<"const char called"<<endl;
    char* tmp = new char(strlen(str)+1);
    strcpy(tmp, str);
    swap(ch, tmp);
}

MyString::MyString(const string str){
    ch = new char(str.size()+1);//size()不包括'\0'
    strcpy(ch , str.c_str());//c_str()保证有结尾符'\0'，data()不保证
}

MyString::MyString(const MyString& str){
    cout<<"copy constructor called"<<endl;
    char* tmp = new char(strlen(str.ch)+1);
    strcpy(tmp, str.ch);
    swap(ch, tmp);
}

MyString::MyString(MyString&& str){//移动构造函数
    cout<<"move constructor called"<<endl;
    swap(ch, str.ch);
}

MyString& MyString::operator = (const MyString& str){
    cout<<"operater= called"<<endl;
    if(this == &str)return *this;          //处理自我赋值的情况
    char* tmp = new char(strlen(str.ch)+1);//异常安全，若new分配内存失败也不会丢失ch中的内容
    strcpy(tmp, str.ch);
    swap(ch, tmp);
    return *this;
}

MyString& MyString::operator = (MyString&& str){//移动赋值号
    cout<<"move operater= called"<<endl;
    swap(ch, str.ch);
    return *this;
}

MyString& MyString::operator +=(const MyString& str){
    char* tmp = new char(size()+str.size()+2);
    strcpy(tmp, ch);
    strcat(tmp, str.ch);
    swap(tmp, ch);
    return *this;
} 

int MyString::compare(const MyString& str){
    return strcmp(ch, str.ch);
}
MyString operator+(const MyString& str1, const MyString& str2){
    cout<<"str1 "<<str1<<" str2 "<<str2<<endl;
    MyString tmp(str1);
    cout<<"tmp "<<tmp<<endl;
    return tmp+=str2;
}
ostream& operator<<(ostream& os, const MyString& str){
    os << str.ch;
    return os;
}
istream& operator>>(istream& is, MyString& str){
    string tmp;
    cout<<"please input a string:";
    getline(cin,tmp);
    char* tmp_c = new char(tmp.size()+1);
    strcpy(tmp_c, tmp.c_str());
    swap(str.ch, tmp_c);
    return is;
}

bool operator==(const MyString& str1, const MyString& str2){
    return strcmp(str1.ch, str2.ch) == 0;
}

template<typename T>
void MoveSwap(T& a, T& b){
    T tmp(move(a));
    a = move(b);
    b = move(tmp);
}
int main(){
    MyString t("duan");
    MyString t1("xian");
    cout<<t<<endl;
    cout<<t1<<endl;
    swap(t,t1);//若类中没有移动构造函数和移动赋值号，则会调用拷贝构造函数和赋值号函数，需要申请空间，执行深拷贝，交换指针，然后函数结束后，析构对象释放空间
    cout<<t<<endl;
    cout<<t1<<endl;
    MyString t2;
    t2 = t1;
    cout<<"t = "<<t<<endl;
    cout<<"t1 = "<<t1<<endl;
    cout<<"t2 = "<<t2<<endl;
    MyString t3;
    cout<<"input:";
    cin>>t3;
    cout<<t3<<endl;
    cout<<t3.size()<<endl;
    cout<<(t3+=t1)<<endl;
    cout<<(t1+t2)<<endl;
    cout<<"t==t1 "<<(t==t1)<<endl;
    cout<<"t==t3 "<<(t==t3)<<endl;
    cout<<"t t1 "<<t.compare(t1)<<endl;
    cout<<"t t3 "<<t.compare(t3)<<endl;
    cout<<t[0]<<endl;
    
    char str1[] = "test";
    char str2[] = "ab";
    strncpy(str1, str2, 2);
    cout<<str1<<endl;
    cout<<str2<<endl;
    return 0;
}