#include <iostream>
#include <string>
#include <vector>

using namespace std;

int KMP(const string& s, const string& p, vector<int>& next){
    int i = 0, j = 0;
    int len1 = s.size(), len2 = p.size();//s.size()返回的是无符号的整数，必须转成int，因为p可能为-1
    int res = 0;
    while(i < len1 && j < len2){
        if(j == -1 || s[i] == p[j]){//一个字符也不匹配或者当前字符匹配
            ++i;
            ++j;
            if(j == len2){
                ++res;
                j = next[j];
            }
        }
        else
            j = next[j];//不匹配，标兵j返回指定位置
    }
    return res;
    //if(j == p.size())return i - j;
    //return -1;
}
void getNext(const string& p, vector<int>& next){
    next[0] = -1;
    size_t i = 0; 
    int j = -1;
    while(i < p.size()){
        if(j == -1 || p[i] == p[j]){
            ++i;
            ++j;
            next[i] = j;//下一个点记下匹配长度
        }
        else
            j = next[j];
    }
}
int main(){
    string str, p;
    cin>>str;
    cin>>p;
    vector<int> next(str.size(), 0);
    getNext(str, next);
    int res = KMP(str, p, next);
    cout<<res<<endl;
    return 0;
}