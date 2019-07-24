#include <iostream>
#include <vector>

using namespace std;

void heapSort(vector<int>& ve){
    for(int i=1;i<ve.size();i++){
        int father_index = (i-1) / 2;
        int child_index = i;
        while(ve[father_index]>ve[child_index]){
            swap(ve[father_index], ve[child_index]);
            child_index = father_index;
            father_index = (child_index - 1) / 2;
        }
    }
    for(int j=ve.size()-1;j>=0;j--){
        swap(ve[0], ve[j]);
        int father_index = 0;
        while(father_index < j){
            int left = 2 * father_index + 1<j? ve[2 * father_index + 1] : INT32_MAX;
            int right = 2 * father_index + 2<j?ve[2 * father_index + 2] : INT32_MAX;
            if(left==right&&left==INT32_MAX)break;
            int index = 2 * father_index + (left < right? 1 : 2);
            if(ve[father_index]<ve[index])break;
            swap(ve[father_index], ve[index]);
            father_index = index; 
        }
    }
}
int main(){
    int a[] = {1,5,3,2,4,7,8,9,100,10,11};
    vector<int> ve;
    for(int i=0;i<11;i++)ve.push_back(a[i]);
    heapSort(ve);
    for(int i=0;i<ve.size();i++)cout<<ve[i]<<" ";
    return 0;
}
