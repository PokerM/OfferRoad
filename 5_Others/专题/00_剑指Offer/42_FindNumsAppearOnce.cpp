//version 1
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        set<int> s;
        for(auto const d : data){
            auto const it = s.find(d);
            if(it!=s.end()){
                s.erase(it);
            }
            else{
                s.insert(d);
            }
        }
        auto it = s.begin();
        *num1 = *it;
        it++;
        *num2 = *it;
        return;
    }
};

//version 2
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {

        int diff = accumulate(data.begin(), data.end(), 0, bit_xor<int>());//全部元素进行异或，得到两个不同元素异或结构
        // Get its last set bit，取出最后一个为1的位，由于两个数字不一样，必然存在其中一位不同，那么只需要找出其中一位，然后按情况区分
        diff &= -diff;
        // Pass 2 :
        *num1 = 0;
        *num2 = 0;
        for (int num : data)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                *num1 ^= num;
            }
            else // the bit is set
            {
                *num2 ^= num;
            }
        }
        return;
    }
};