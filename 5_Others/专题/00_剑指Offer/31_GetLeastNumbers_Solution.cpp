//小规模数据集：数据能全部载入内存，时间复杂度nlogn
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size()<k)return vector<int>();
        sort(input.begin(),input.end());
        input.resize(k);
        return input;
    }
};
//