#include <iostream>

using namespace std;
//f(n) = f(n-1) + f(n-2)+...+f(1)+1=2*(f(n-2)+f(n-3)+...1)=2(2*(f(n-3)+...1))=2^(n-1)*1
class Solution {
public:
    int jumpFloorII(int number) {
        if(number==0)return 0;
        return 1<<--number;
    }
};