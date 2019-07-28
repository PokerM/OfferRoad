#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        if(s.empty())return "";
        stack<string> s_stack;
        int start = -1, len = 0;
        int i=0;
        while(i<s.size()){
            while(len==0&&i<s.size()&&s[i]==' ')++i;
            if(i==s.size())break;
            if(s[i]==' '){
                s_stack.push(s.substr(start, len));
                start = -1;
                len = 0;
            }
            else{
                ++len;
                if(start==-1)start = i;
            }
            ++i;
        }
        if(start!=-1){
            s_stack.push(s.substr(start, len));
        }
        string res;
        while(!s_stack.empty()){
            auto t = s_stack.top();
            s_stack.pop();
            res.append(t);
            if(!s_stack.empty())res.append(" ");
        }
        return res;
    }
};

int main(){
    Solution so;
    string res = so.reverseWords("  hello world!  ");
    cout<<res<<endl;
    return 0;
}