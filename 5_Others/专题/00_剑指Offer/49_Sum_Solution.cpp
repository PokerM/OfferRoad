class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));//ans为0时，不计算后面部分
        return ans;
    }
};