#include <iostream>
#include <vector>
#include <string>

using namespace std;

int KMP(string& source, string& target, vector<int>& next){
    int i = 0, j=0;
    int len1 = source.size(), len2 = target.size();
    while(i<len1 && j<len2){
        if(j == -1 || source[i] == target[j]){
            ++i;
            ++j;
        }
        else{
            j = next[j];
        }
    }
    if(j==len2)return i - j;
    return -1;
}
void getNext(string& source, vector<int>& next){
    next[0] = -1;
    int i = 0, j = -1;
    while(i<next.size()){
        if(j == -1 || source[i] == source[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    vector<int> next(s1.size(), 0);
    getNext(s1, next);
    int res = KMP(s1, s2, next);
    cout<<res<<endl;
    return 0;
}
