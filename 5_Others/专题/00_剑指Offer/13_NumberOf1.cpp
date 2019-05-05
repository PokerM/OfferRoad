class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int un;
         if(n<0) un = 0xffffffff + n + 1;
         else un = n;
         int res = 0;
         while(un!=0){
             if(un%2==1)res++;
             un = un>>1;
         }
         return res;
     }
};