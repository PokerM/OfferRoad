#include <iostream>

using namespace std;


int main(){
    string s1, s2;
    cin>>s1>>s2;
    // cout<<s1<<endl;
    // cout<<s2<<endl;

    size_t len1 = s1.size(), len2 = s2.size();
    string res(len1+len2, '0');
    for(int i=len1-1;i>=0;i--){
        int add = 0;
        for(int j=len2-1;j>=0;j--){
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int sum = res[i + j + 1] - '0' + mul + add;
            res[i + j + 1] = sum % 10 + '0';
            cout<<i+j+1<<" "<<res[i+j+1]<<endl;;
            add = sum / 10; 
        }
        res[i] += add;
        cout<<res[i]<<endl;
    }
    for(int i=0;i<res.size();i++)
        if(res[i]!='0'){
            cout<<res.substr(i);
            break;
        }
    return 0;
}
