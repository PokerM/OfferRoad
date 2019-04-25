#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ones = 0, twos = 0;
//         vector<int>::iterator it = nums.begin();
//         for(;it != nums.end(); it++){
//             ones = (ones ^ (*it)) & ~twos;
//             twos = (twos ^ (*it)) & ~ones;
//             cout<<(*it)<<" one = "<<ones<<" twos = "<<twos<<endl;
//         }
//         return ones;
//     }
// };

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         int r = 0, n = nums.size(), i = 0, last = 0;
        
        
//         for (i = 0; i < n; ++i) 
//             r ^= nums[i];
//         last = r & (~(r - 1));
//         cout<<"r = "<<r<<" last = "<<last<<" "<<endl;
//         vector<int> ret(2, 0);
//         for (i = 0; i < n; i++)
//         {
//             cout<<"1 ret_0 = "<<ret[0]<<" ret_1 = "<<ret[1]<<endl;
//             if ((last & nums[i]) != 0)
//                 ret[0] ^= nums[i];
//             else
//                 ret[1] ^= nums[i];
//             cout<<"ret_0 = "<<ret[0]<<" ret_1 = "<<ret[1]<<endl;
//         }
        
//         return ret;
//     }
// };

// class Solution
// {
// public:
//     vector<int> singleNumber(vector<int>& nums) 
//     {
//         // Pass 1 : 
//         // Get the XOR of the two numbers we need to find
//         int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
//         // Get its last set bit
//         diff &= -diff;
//         cout<<"diff "<<diff<<endl;
//         // Pass 2 :
//         vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
//         for (int num : nums)
//         {
//             if ((num & diff) == 0) // the bit is not set
//             {
//                 rets[0] ^= num;
//             }
//             else // the bit is set
//             {
//                 rets[1] ^= num;
//             }
//             cout<<"ret_0 = "<<rets[0]<<" ret_1 = "<<rets[1]<<endl;
//         }
//         return rets;
//     }
// };
int main(){
    int a[]  = {1,1,4,4,3,6};
    vector<int> ve;
    for(int i=0;i<6;i++){
        ve.push_back(a[i]);
    }
    Solution so;
    auto res = so.singleNumber(ve);
    cout<<"res = "<<res[0]<<" "<<res[1]<<endl;
    return 0;
}