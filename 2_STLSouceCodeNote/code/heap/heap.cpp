#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Heap{
public:
    Heap():p(1){
        ve.push_back(0);
    };
    void push(T);
    T pop();
    bool empty(){
        return p==1;
    }
    vector<T> ve;
private:
    int p;
};

template<typename T>
void Heap<T>::push(T t){
    ve.push_back(t);
    if(p < ve.size()-1)
        swap(ve[p], ve.back());
    //上滤
    int tmp = p;
    while(tmp/2>0&&ve[tmp/2]<ve[tmp]){
        swap(ve[tmp/2], ve[tmp]);
        tmp = tmp / 2;
    }
    p++;
    return;
}

template<typename T>
T Heap<T>::pop(){
    T res = ve[1];
    swap(ve[1], ve[--p]);
    //下溯
    int i=1;
    while(2*i<p){
        if(ve[2*i]<=ve[i]&&(2*i+1>=p || ve[2*i+1] <= ve[i]))break;
        int q = 2*i;
        if(2*i+1<p&&ve[2*i+1]>=ve[2*i])q++;
        swap(ve[i], ve[q]);
        i = q;
    }
    return res;
}
int main(){
    Heap<int> heap;
    int a[] = {0,4,6,7,5,3,5,7};
    for(auto i : a){
        heap.push(i);
    }
    while(!heap.empty()){
        cout<<"pop:"<<heap.pop()<<endl;
        //for(auto i:heap.ve)cout<<i<<" ";
        //cout<<endl;
    }
    return 0;
}