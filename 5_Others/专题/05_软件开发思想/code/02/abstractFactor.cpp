#include <iostream>

using namespace std;
class product{
public:
    virtual void printName() = 0;
    virtual void printSerial() = 0;
};
class productA : public product{
public:
    void printName(){
        cout<<"product A"<<endl;
    }
};
class productA1 : public productA{
public:
    void printSerial(){
        cout<<"serial 1"<<endl;
    }
};
class productA2 : public productA{
public:
    void printSerial(){
        cout<<"serial 2"<<endl;
    }
};
class productB : public product{
public:
    void printName(){
        cout<<"product B"<<endl;
    }
};
class productB1 : public productB{
public:
    void printSerial(){
        cout<<"serial 2"<<endl;
    }
};
class productB2 : public productB{
public:
    void printSerial(){
        cout<<"serial 2"<<endl;
    }
}; 
class factor{
public:
    virtual productA* makeProductA() = 0;
    virtual productB* makeProductB() = 0;
};
class factor1 : public factor{
public:
    virtual productA* makeProductA(){
        return new productA1();
    }
    virtual productB* makeProductB(){
        return new productB1();
    }
};
class factor2 : public factor{
public:
    virtual productA* makeProductA(){
        return new productA2();
    }
    virtual productB* makeProductB(){
        return new productB2();
    }
};
int main(){
    factor* f = new factor1;
    product* p = f->makeProductA();
    p->printName();
    p->printSerial();
    delete p;
    delete f;
    f = new factor2;
    p = f->makeProductA(); 
    p->printName();
    p->printSerial();
    delete p;
    return 0;
}