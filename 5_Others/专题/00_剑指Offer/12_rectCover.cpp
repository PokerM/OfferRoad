//两种形态：竖着(n-1)和横着(n-2)
//f(n) = f(n-1) + f(n-2)
class Solution {
public:
    int rectCover(int number) {
        int res = 0,f_n_1 = 1, f_n = 2;
        if(number<3)return number;
        for(int i=3;i<=number;i++){
            res = f_n_1 + f_n;
            f_n_1 = f_n;
            f_n = res;
        }
        return res;
    }
};