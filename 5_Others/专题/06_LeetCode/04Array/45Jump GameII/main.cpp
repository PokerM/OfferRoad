#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void find_place(vector<int>& nums, int cur, int place){
        if(nums.size()==1){
            nums.push_back(place);
            return;
        }
        int mid;
        int s=0,e=nums.size()-1;
        while(e-s>1){
            mid=(e+s)>>1;
            if(cur==nums[mid]){
                e=mid;
                break;
            }
            if(cur<nums[mid]){
                s=mid;
            }
            else{
                e=mid;
            }
        }
        nums.erase(nums.begin()+e+1,nums.end());
        nums.push_back(place);
    }
    int jump(vector<int>& nums) {
        int vec_size=nums.size();
        if(vec_size<2)return 0;
        vector<int> cur_vec;
        int i=vec_size-2;
        for(;i>=0;i--){
            if(cur_vec.empty()){
                if(nums[i]!=0){
                    cur_vec.push_back(i);
                }
                continue;
            }
            if(nums[i]+i>=vec_size-1){
                cur_vec.clear();
                cur_vec.push_back(i);
                continue;
            }
            if((nums[i]+i)==*(cur_vec.end())){
                cur_vec.push_back(i);
                continue;
            }
            if(nums[i]+i>*(cur_vec.end())){
                find_place(cur_vec,nums[i]+i,i);
            }
        }
        return cur_vec.size();
    }
};
int main()
{
    Solution so;
    int a[]={1,1,1,2,1};
    vector<int> nums;
    for(int i=0;i<5;i++){
        nums.push_back(a[i]);
    }
    int res = so.jump(nums);
    cout << res << endl;
    return 0;
}
