#include <iostream>

using namespace std;
class product{
public:
    virtual void printName() = 0;
};
class productA : public product{
public:
    void printName(){
        cout<<"product A"<<endl;
    }
};
class productB : public product{
public:
    void printName(){
        cout<<"product B"<<endl;
    }
}; 
class factory{
public:
    virtual product* makeProduct() = 0;
};
class factoryA : public factory{
public:
    virtual product* makeProduct(){
        return new productA();
    }
};
class factoryB : public factory{
public:
    virtual product* makeProduct(){
        return new productB();
    }
};
int main(){
    factory* f = new factoryA;
    product* p = f->makeProduct();
    p->printName();
    delete p;
    delete f;
    f = new factoryB;
    p = f->makeProduct(); 
    p->printName();
    delete p;
    return 0;
}