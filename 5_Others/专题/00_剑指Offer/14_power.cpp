class Solution {
public:
    double Power(double base, int exponent) {
        long long p = abs((long long)exponent);//考虑为负数的情况
        double r = 1.0;
        while(p){
            if(p & 1) r *= base;//奇数
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1/ r : r;
    }
};