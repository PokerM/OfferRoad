#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int rob_rec(vector<int>& nums, vector<int>& res, int s, int e){
        if(e-s==0)return nums[e];
        if(e-s==1)return max(nums[s],nums[s+1]);
        if(res[e]!=-1)return res[e];
        return res[e]=max(rob_rec(nums,res,s,e-2)+nums[e],rob_rec(nums,res,s,e-1));
    }
    int rob(vector<int>& nums) {
        if(!nums.size())return 0;
        if(nums.size()==1)return nums[0];
        vector<int> res1(nums.size(),-1);
        vector<int> res2(nums.size(),-1);
        return max(rob_rec(nums,res1, 0, nums.size()-2),rob_rec(nums,res2, 1, nums.size()-1));
    }
};
int main()
{
    Solution so;
    int a[]={1,2,1,1};
    vector<int> nums;
    for(int i=0;i<4;i++){
        nums.push_back(a[i]);
    }
    cout<<so.rob(nums);
    return 0;
}
