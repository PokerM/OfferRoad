//思路：保存一个丑数数组，和三个质数因子指针，每次往前移动一次指针（只移动下一个丑数对应的指针）
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 1)return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0；//质数因子指针
        int i;
        for (i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2)t2++;
            if (res[i] == res[t3] * 3)t3++;
            if (res[i] == res[t5] * 5)t5++;
        }
        return res[index - 1];
    }
};