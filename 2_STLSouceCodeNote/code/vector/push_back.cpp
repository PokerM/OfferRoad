#include <iostream>
#include <vector>

using namespace std;

class Base{
public:
    Base(int t){
        a = t;
        cout<<"constructor called"<<endl;
    }
    Base(const Base& b){
        a = b.a;
        cout<<"copy constructor called"<<endl;
    }
    int a;
};
int main(){
    Base b(1);
    //b.a = 1;
    vector<Base> vb;
    vb.push_back(b);
    vb.push_back(5);
    //vb[0].a = 2;
    cout<<b.a<<" "<<vb[0].a<<endl;
    return 0;
}