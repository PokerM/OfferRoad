#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;
//将一个字符串分割为所有子串都是回文子串的情况，给出所有分割的情况
//分析：最坏情况：T(n) = T(n-1) + T(n-2) + ... T(1) = 2 * (T(n-2) + ... + T(1)) = 2 ^ (n - 1);
//最坏情况时，string为类似于aaaaaaaaaaaa，这样的情况，其最后结果本身就含有2 ^ (n - 1)种可能。故其最坏情况的复杂度无法降低
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, path, res);
        
        return res;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string>>& res){
        if(index == s.size()){//遍历至最后
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();++i){//判断从index开始，i结束的子串是否为回文子串
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string& s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
};

int main(){
    clock_t start, finish;
    Solution so;
    string s("ababababab");
    for(int i=0;i<50;i++){
        start = clock();
        so.partition(s);
        finish = clock();
        cout<<"len = "<<i+10<<" time = "<<(finish - start)<<"(ms)"<<endl;
        if(i&1)s.append("b");
        else s.append("a");
    }
    return 0;
}