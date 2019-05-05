class Solution {
public:
    //f(n) = f(n-1) + f(n-2)
    int Fibonacci(int n) {
        int f_n_2 = 0,f_n_1 = 1,res=0;
        if(n==1)return 1;
        for(int i=2;i<=n;i++){
            res = f_n_2 + f_n_1;
            f_n_2 = f_n_1;
            f_n_1 = res;
        }
        return res;
    }
};