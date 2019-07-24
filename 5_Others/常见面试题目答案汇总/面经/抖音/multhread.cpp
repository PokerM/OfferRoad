#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>

using namespace std;
vector<mutex> vm(3);
int num = 1;
void print(int id){
    int t = 0;
    while(t<10){
        vm[id].lock();
        cout<<"thread "<<id<<":"<<num<<endl;
        ++num;
        if(id==2){
            vm[0].unlock();
        }
        else vm[id+1].unlock();
        ++t;
    }
}
int main(){
    vm[1].lock();
    vm[2].lock();
    thread t1(print, 0);
    thread t2(print, 1);
    thread t3(print, 2);
    t1.join();
    t2.join();
    t3.join();
    //cout<<at<<endl;
    return 0;
}