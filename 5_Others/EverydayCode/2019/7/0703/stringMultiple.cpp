#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int len = s1.size() + s2.size();
    vector<int> ve(len, 0);
    for(int i=s1.size()-1;i>=0;i--){
        int x = s1[i] - '0';
        for(int j=s2.size()-1;j>=0;j--){
            int y = s2[j] - '0';
            ve[i+j] += (ve[i+j+1] + x * y) / 10;
            ve[i+j+1] = (ve[i+j+1] + x * y) % 10;
        }
    }
    string res;
    for(int i=0;i<ve.size();i++){
        if(i==0&&ve[0]==0)continue;
        res.append(to_string(ve[i]));
    }
    cout<<res<<endl;
    return 0;
}