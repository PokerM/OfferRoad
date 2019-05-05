//青蛙跳台阶：1阶或2阶
class Solution {
public:
    //0 1 1 2 3 5 8...
    //f(n) = f(n-1) + f(n-2)
    int jumpFloor(int number) {
        int f_n_1 = 1,f_n = 1,res=0;
        if(number<=1)return number;
        for(int i=2;i<=number;i++){
            res = f_n_1 + f_n;
            f_n_1 = f_n;
            f_n = res;
        }
        return res;
    }
};