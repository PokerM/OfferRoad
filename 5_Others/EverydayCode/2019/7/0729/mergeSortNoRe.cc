#include <iostream>
#include <vector>

using namespace std;
void mergeSort(vector<int>& nums){
    size_t len = 1;
    while(len < nums.size()){
        size_t p = 0, q = len;
        while(p < nums.size() && q < nums.size()){
            size_t times = 0;
            size_t i = 0, j = 0;
            while(i < len && j < len && q + j< nums.size()){
                int headA = nums[p + i], headB[q + j];
                if(headA>headB){
                    nums[p + i] = headB;
                    j++;
                }
                i++;
            }
        }
    }
}
int main(){

    return 0;
}
