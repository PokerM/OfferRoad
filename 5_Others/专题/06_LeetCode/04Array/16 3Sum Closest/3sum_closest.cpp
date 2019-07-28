#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int res = nums[0]+nums[1]+nums[2]-target;
        sort(nums.begin(),nums.end());//排序
        for(int i=0;i<len-2;i++){
            if(i==0||nums[i]!=nums[i-1]){//跳过相同数字
                int lo = i+1;
                int hi = len -1;
                //双向扫描
                while(lo<hi){
                    int t = nums[lo]+nums[hi]+nums[i]-target;
                    if(t==0)return target;
                    if(abs(t)<=abs(res)){
                        res = t;
                        while(lo<hi&&nums[lo]==nums[++lo]);
                        while(lo<hi&&nums[hi]==nums[--hi]);
                    }    
                    else 
                        if(t<0)lo++;
                        else hi++;
                }
            }
        }
        return res+target;
    }
};

int main(){
    Solution so;
    int a[] = {1,1,-1,-1,3};
    vector<int> ve;
    for(int i=0;i<4;i++)ve.push_back(a[i]);
    int res = so.threeSumClosest(ve,1);
    cout<<res;
    return 0;
}