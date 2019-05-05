#include <iostream>
#include <cstring>

using namespace std;

class MyString{
public:
    //MyString(){};
    MyString(char* pData = NULL){
        m_pData = pData;
    }
    ~MyString(){
        if(m_pData != NULL)delete m_pData;
    };

    //考虑异常安全性的赋值操作符重载
    MyString& operator = (const MyString& m_str){//返回引用是为了能够连续赋值，const引用传值防止构造临时变量和修改传入参数
        if(this != &m_str){                   //判断自我赋值
            MyString strTemp(m_str);          //构造临时局部变量用于交换内容并自动调用析构函数，删除原来空间。若此时内存分配失败，原来内容不会改变
            char* temp = strTemp.m_pData;      
            strTemp.m_pData = m_pData;
            m_pData = temp;
        }
        return *this;
    }

    //不考虑异常安全性的赋值操作符重载
    MyString& operator = (const MyString& m_str){
        if(this == &m_str)return *this;

        delete m_pData;
        m_pData = NULL;

        m_pData = new char[strlen(m_str.m_pData) + 1];//若在此时，内存分配失败，抛出异常，原来内容丢失
        strcpy(m_pData, m_str.m_pData);

        return *this;
    }
    void printString(){
        cout<<m_pData<<endl;
    }
private:
    char* m_pData;
};
int main(){
    char c[] = {'d','u','a','n','\0'};
    MyString str(c),test;
    str.printString();
    test = str;
    test.printString();
    return 0;
}