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
class singleFactor{
public:
    static product* makeProduct(int kind){
        if(kind == 0)return new productA;
        return new productB;
    }
};
int main(){
    product* p = singleFactor::makeProduct(0);
    p->printName();
    delete p;
    p = singleFactor::makeProduct(1);
    p->printName();
    delete p;
    return 0;
}