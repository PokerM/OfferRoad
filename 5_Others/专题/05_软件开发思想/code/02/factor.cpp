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
class factor{
public:
    virtual product* makeProduct() = 0;
};
class factorA : public factor{
public:
    virtual product* makeProduct(){
        return new productA();
    }
};
class factorB : public factor{
public:
    virtual product* makeProduct(){
        return new productB();
    }
};
int main(){
    factor* f = new factorA;
    product* p = f->makeProduct();
    p->printName();
    delete p;
    delete f;
    f = new factorB;
    p = f->makeProduct(); 
    p->printName();
    delete p;
    return 0;
}