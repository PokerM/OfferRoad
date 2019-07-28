class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if(nums.empty())return vector<int>();
        if(nums.size()==1)return vector<int>(1,-1);
        stack<pair<int,int>> s;
        vector<int> res(nums.size(),0);
        s.push({nums[0],0});
        int i=1;
        int len = nums.size();
        bool over = false;
        bool twice = false;
        while(!s.empty()){
            while(!s.empty()&&s.top().first<nums[i]){
                res[s.top().second] = nums[i];
                s.pop();
            }
            if(!over){
                s.push({nums[i],i});  
            }
            i++;
            if(i==len){
                if(over){
                    while(!s.empty()){
                        res[s.top().second] = -1;
                        s.pop();
                    }
                }
                else{
                    i=0;
                    over = true;
                }
            }
        }
        return res;
    }
};