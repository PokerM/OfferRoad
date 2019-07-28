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
        int sum1 = sum;
        int num = 0;
        for(int i=e-1;i>=s;i--){
            if(nums.at(i)>=temp){
                sum++;
                nums.push_back(nums.at(i));
                nums.erase(it+i);
                e--;
                num++;
            }
        }
        for(int i=0;i<nums.size();i++)cout<<nums[i]<< " ";
        if(sum==t)return temp;
        if(sum<t){
            cout<<"K="<<t<<" S="<<s<<" E="<<e-1<<endl;
            return findNumBigger(nums,t,s,e-1);
        }
        else {
            cout<<"K="<<t-sum1+1<<" S="<<nums.size()-num<<" E="<<nums.size()-1<<endl;
            return findNumBigger(nums,t-sum1+1,nums.size()-num,nums.size()-1);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        return findNumBigger(nums, k, 0, nums.size()-1);
    }
};
int main()
{
    int a[]={3,2,3,1,2,4,5,5,6};
    vector<int> temp;
    for(int i=0;i<9;i++){
        temp.push_back(a[i]);
    }
    Solution so;
    cout<<so.findKthLargest(temp,7);
    return 0;
}
