class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> s;
        int i = T.size()-1;
        vector<int> res(i+1,0);
        for(;i>=0;i--){
            while(!s.empty()&&T[i]>=s.top().first){
                s.pop();
            }
            if(s.empty())res[i]=0;
            else res[i]=s.top().second - i;
            s.push({T[i],i});
        }
    return res;
    }
};