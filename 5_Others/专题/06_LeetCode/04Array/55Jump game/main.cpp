#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = nums.size();
        if(i<2)return true;
        i--;
        bool zero=false;
        int zero_po=0;
        nums[i]+=1;
        for(;i>=0;i--){
            if(!zero){
                if(nums[i]!=0)continue;
                zero = true;
                zero_po = i;
            }
            else{
                if(nums[i]+i>zero_po){
                    zero = false;
                }
            }
        }
        return !zero;
    }
};
int main()
{
    Solution so;
    int a[]={1,2,0,1};
    vector<int> nums;
    for(int i=0;i<4;i++){
        nums.push_back(a[i]);
    }
    bool res = so.canJump(nums);
    cout << res << endl;
    return 0;
}
