#include <iostream>
#include <cstring>

using namespace std;


class MyString ;
istream& operator>>(istream& is, const MyString& str); //输入运算符重载
ostream& operator<<(ostream& os, const MyString& str); //输出运算符重载
MyString operator + (const MyString&, const MyString&);
bool operator==(const MyString&, const MyString&);
class MyString{
public:
    MyString(){};
    MyString(string str);
    MyString(const char* str);           //构造函数
    MyString(const MyString& str);      //拷贝构造函数，注意为const引用传值
    MyString& operator = (const MyString& str); //赋值操作符重载

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
    char ch[1000];
};

MyString::MyString(const char* str){
    cout<<"const char called"<<endl;
    memmove(ch, str, strlen(str)+1);//memmove能处理区域重叠的情况，memcpy不能，故采用memmove.strlen(char*)不包括'\0'
}

MyString::MyString(const string str){
    str.copy(ch, str.size(), 0);
    ch[str.size()] = '\0';
    //cout<<ch<<endl;
}

MyString::MyString(const MyString& str){
    memmove(ch,str.ch,strlen(str.ch)+1);
}

MyString& MyString::operator = (const MyString& str){
    if(this != &str){//处理自我赋值的情况
        cout<<"str size "<<strlen(str.ch)<<endl;
        memmove(ch, str.ch, strlen(str.ch)+1);
    }
    return *this;
}

MyString& MyString::operator +=(const MyString& str){
    strcat(ch, str.ch);
    return *this;
} 

int MyString::compare(const MyString& str){
    return strcmp(ch, str.ch);
}
MyString operator+(const MyString& str1, const MyString& str2){
    MyString tmp(str1);
    return tmp+=str2;
}
ostream& operator<<(ostream& os, const MyString& str){
    os << str.ch;
    return os;
}
istream& operator>>(istream& is, MyString& str){
    // char c;
    // int i=0;
    // while(1){
    //     is >> noskipws ;
    //     is >> c;
    //     if(c != '\n'){
    //         str.ch[i] = c;
    //         i++;
    //     }
    //     else
    //         break;
    // }
    is>>str.ch;
    return is;
}

bool operator==(const MyString& str1, const MyString& str2){
    return strcmp(str1.ch, str2.ch) == 0;
}
int main(){
    MyString t("duan");
    MyString t1(t);
    MyString t2;
    t2 = t1;
    cout<<t<<endl;
    cout<<t1<<endl;
    cout<<t2<<endl;
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
    return 0;
}