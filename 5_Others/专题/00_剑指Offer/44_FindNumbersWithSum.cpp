//两指针遍历，时间复杂度为N
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.size() < 2)return vector<int>();
        int lhs = 0, rhs = array.size() - 1;
        vector<int> res;
        while(lhs < rhs){
            int t = array[lhs] + array[rhs];
            if(t == sum){
                res.push_back(array[lhs]);
                res.push_back(array[rhs]);
                return res;
            }
            if(t < sum)
                lhs++;
            else
                rhs--;
        }
        return res;
    }
};