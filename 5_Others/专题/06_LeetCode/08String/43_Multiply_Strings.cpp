#include <iostream>
#include <string>
/*
字符串乘法：从最低位开始逐步计算
 */
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1==0 || len2==0)return string("");
        string res(len1 + len2, '0');
        for(int i=len1-1;i>=0;i--){
            int add = 0;
            for(int j=len2-1;j>=0;j--){
                int mul = (num1[i]-'0') * (num2[j]-'0');//计算该位乘法
                int sum = res[i+j+1] - '0' + mul + add;//求和
                res[i+j+1] = sum % 10 + '0';//更新该位
                add = sum / 10;//更新进位
                cout<<"num1 = "<<num1[i]<<" num2 = "<<num2[j]<<" sum = "<<sum<<" add = "<<add<<" res["<<i+j+1<<"] = "<<res[i+j+1]<<endl;
            }
            res[i] += add;//进位
        }
        for(int i=0;i<len1+len2;i++)
            if(res[i]!='0')return res.substr(i);//去掉头部0
        return "0";
    }
};

int main(){
    Solution so;
    string s1, s2;
    cin>>s1>>s2;
    string res = so.multiply(s1, s2);
    cout<<"res = "<<res<<endl;
    return 0;
}