#include <iostream>
#include <string>
#include <vector>


using namespace std;
//马拉车最长回文子串
//p[i]:以i为中心的最长回文子串的长度
//mx:最右边界，mx下标对应的字符不是回文字符
//id:最右边界对应的回文中心
void manacher(string& s, vector<int>& p){
    p[0] = 1;
    int mx = 0;
    int id = 0;
    int i=1;
    while(i<s.size()){
        p[i] = mx>i?(min(p[2*id-i], mx-i)) : 1;
        while(s[i-p[i]]==s[i+p[i]])p[i]++;
        if(i+p[i]>id+p[id]){
            mx = i + p[i];
            id = i;
        }
        ++i;
    }
}
int main(){
    string s;
    cin>>s;
    int len = s.size();
    string str(2 * len + 2, '#');
    // for(int i=len-1;i>=0;i--){
    //     //str[(i<<1)+1]='#';
    //     str[(i<<1)+2]=s[i];
    // }
    for(int i=0;i<len;i++){
        str[(i<<1)+2] = s[i];
    }
    str[0] = '@';
    cout<<str<<endl;
    vector<int> p(2*len+2, 0);
    manacher(str, p);
    int max_i = 0;
    int max_len = 0;
    for(int i=0;i<p.size();i++){
        if(p[i]>max_len){
            max_len = p[i];
            max_i = i;
        }
    }
    int start = (max_i - max_len) / 2;
    int end = (max_i + max_len - 4) / 2;
    cout<<s.substr(start, end - start + 1)<<endl;
    return 0;
}
