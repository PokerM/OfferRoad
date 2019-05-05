//时间复杂度N
//思路：记录当前子序列和，每当子序列和小于0时，丢弃该子序列，和归0
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())return 0;
        int res = array[0];
        int t = res>0?res:0;
        for(int i=1;i<array.size();i++){
            t += array[i];//子序列和
            if(res<t)res=t;
            t = t>0?t:0;//小于0则归0
        }
        return res;
    }
};