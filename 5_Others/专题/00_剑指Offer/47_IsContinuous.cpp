//记录是否重复和其最大值和最小值
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5)return false;
        vector<bool> num(13,false);//记录是否重复，重复返回false
        int max_num =0 ,min_num=13;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i] == 0)continue;
            if(num[numbers[i]-1])return false;
            num[numbers[i]-1] = true;
            min_num = min_num<numbers[i]?min_num:numbers[i];
            max_num = max_num>numbers[i]?max_num:numbers[i];
            if(max_num - min_num>4)return false;
        }
        return true;
    }
};