class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty())
            return ans;
        chang(str, 0, str.size());
        sort(ans.begin(),ans.end());
        auto it = unique(ans.begin(),ans.end());//将重复内容交换到后端，并返回不重复部分的尾部
        ans.resize(distance(ans.begin(),it));
        return ans;
         
    }
    void chang(string &str,int start,int len){
        if(start == len)
            ans.push_back(str);
        for(int i = start; i < len; i++){
            swap(str[start],str[i]);//剩余部分依次定为一个元素
            chang(str, start+1,len);//得到该情况的所有结果
            swap(str[start],str[i]);//复位
        } 
    }
private:
    vector<string> ans;
};