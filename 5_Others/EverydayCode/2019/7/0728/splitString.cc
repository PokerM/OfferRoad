#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string& s, int lhs, int rhs){
    while(lhs<rhs){
        if(s[lhs++]!=s[rhs--])return false;
    }
    return true;
}
void re(string& s, vector<vector<string>>& res, vector<string>& path, int index){
    if(index == s.size()){
        res.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s, index, i)){
            path.push_back(s.substr(index, i - index + 1));
            re(s, res, path, i+1);
            path.pop_back();
        }
    }
}
void getSplit(string& s, vector<vector<string>>& res){
    if(s.empty())return;
    vector<string> path;
    re(s, res, path, 0);
}
int main(){
    string s;
    cin>>s;
    vector<vector<string>> res;
    getSplit(s, res);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"res num = "<<res.size()<<endl;
    return 0;
}
