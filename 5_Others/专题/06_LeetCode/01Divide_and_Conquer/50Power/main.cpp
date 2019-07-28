#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        stack<int> stk;
        double res = 1.0;
        while(n!=0){
            stk.push(n%2);
            n/=2;
        }
        while(!stk.empty()){
            res*=res;
            if(stk.top()==1)res*=x;
            if(stk.top()==-1)res*=1/x;
            stk.pop();
        }
        return res;
    }
};
int main()
{
    Solution so;
    double res = so.myPow(-2.0,9);
    cout<< res << endl;
    return 0;
}
