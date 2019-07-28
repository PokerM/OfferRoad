#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findNumBigger(vector<int>& nums, int t, int s, int e){
        vector<int>::iterator it;
        it = nums.begin();
        int temp = nums.at(e);
        int sum = nums.size() - e;
        for(int i=e-1;i>=s;i--){
            if(nums.at(i)>=temp){
                sum++;
                nums.push_back(nums.at(i));
                nums.erase(it+i);
            }
        }
        if(sum==t)return temp;
        if(sum<t)
            e=nums.size()-sum-1;
        else
            s=nums.size()-sum+1;
        return findNumBigger(nums, t, s, e);
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1)return nums.at(0);
        return findNumBigger(nums, k, 0, nums.size()-1);
    }
};
int main()
{
    Solution so;
    vector<int> nums;
    int a[]={0,1,2,3,4,5,6,7};
    for(int i=0;i<8;i++){
        nums.push_back(a[i]);
    }
    return so.findKthLargest(nums,1);
}
