#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.
 */
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()<2)return nums;
        sort(nums.begin(), nums.end());
        
        vector<int> T(nums.size(), 0);
        vector<int> Parent(nums.size(), 0);
        
        int m = 0, mi = 0;
        for(int i=nums.size()-1;i>=0;i--){
            //更新T[i]，遍历右边元素，找到能整除nums[i]，并且T[j]+1>T[i]的值
            for(int j=i;j<nums.size();j++){
                if(nums[j]%nums[i]==0&&T[i]<1+T[j]){
                    Parent[i] = j;//存放i元素的父节点
                    T[i] = 1 + T[j];
                    if(T[i]>m){
                        m = T[i];//记录最多的元素个数
                        mi = i;//集合入口
                    }
                }
            }
        }
        vector<int> res;
        for(int i=0;i<m;i++){
            res.push_back(nums[mi]);
            mi = Parent[mi];
        }
        return res;
    }
};
int main(){
    return 0;
}
