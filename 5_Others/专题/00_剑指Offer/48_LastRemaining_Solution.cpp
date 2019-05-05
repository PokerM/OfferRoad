#include <iostream>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0) return -1;
        int s=0;
        for(int i=2;i<=n;i++){
            s=(s+m) % i;
            cout<<s<<" ";
        }
        cout<<endl;
        return s;
    }
};

int main(){
    Solution so;
    so.LastRemaining_Solution(3,2);
    return 0;
}