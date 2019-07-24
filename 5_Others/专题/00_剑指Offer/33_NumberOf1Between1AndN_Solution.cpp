#include <iostream>

/*
按位统计1出现的次数：
假设n=567
个位:567/10=56,567%10=7,那么个位出现1的次数则为56*1 + 1 = 57(11,21,...561  1)
十位:567/100=5,567%100=67，那么十位出现1的次数则为5*10 + 10(510,511,512,...,519)
百位:567/1000=0,567%1000=567,那么百位出现1的次数则为0*100 + 100(100,101...199)
*/
using namespace std;
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n <= 0)return 0;
        
        int count = 0;
        int i = 1;
        while(i <= n){
            int d = i * 10;
            int m = n / d;
            int k = n % d;
            count += i * m;
            cout<<"m = "<<m<<" k = "<<k<<endl;
            if(k >= 2 * i - 1){
                count += i;
            }
            else if(k >= i){
                count += (k - i) + 1;
            }
            i = i * 10;
        }
        return count;
    }
};

int main(){
    Solution so;
    int res = so.NumberOf1Between1AndN_Solution(561);
    cout<<res<<endl;
}