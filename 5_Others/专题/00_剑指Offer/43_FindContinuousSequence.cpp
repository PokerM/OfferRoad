//两指针滑动窗口
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum < 2)return res;
        int cur = 3;
        int lhs = 1,rhs=2;
        while(2*rhs-1<=sum){
            if(cur == sum){
                vector<int> tmp;
                for(int i=lhs;i<=rhs;i++)tmp.push_back(i);
                res.push_back(tmp);
                cur = cur - lhs;
                lhs++;
                rhs++;
                cur += rhs;
            }
            else if(cur<sum){
                rhs++;
                cur+=rhs;
            }
            else if(cur>sum){
                cur = cur - lhs;
                lhs++;
            }
        }
        return res;
    }
};