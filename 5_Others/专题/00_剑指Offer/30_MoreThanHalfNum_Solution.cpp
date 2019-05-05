//version 1:空间换时间，space(n),时间(n)，下面解法更好
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int res = numbers[0];
        int num=1;
        unordered_map<int,int> m;
        m[res]=1;
        for(int i=1;i<numbers.size();i++){
            if(numbers[i]==res){
                num++;
                m[res]++;
            }
            else{
                num--;
                if(num<=0){
                    res=numbers[i];
                    if(m.find(res)!=m.end()){
                        m[res]++;
                    }
                    else{
                        m[res]=1;
                    }
                    num=1;
                }
            }
        }
        return m[res]>(numbers.size()>>1)?res:0;
    }
};

//time:2N
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()) return 0;
        int res = numbers[0];
        size_t count = 1;
        size_t total_count = 1;
        for(size_t i=0;i<numbers.size();i++){
            if(res == numbers[i])
                count++;
            else
                if(--count == 0){
                    res = numbers[i];
                    count = 1;
                }
        }
        count = 0;
        for(size_t i=0;i<numbers.size();i++){
            if(res == numbers[i])count++;
        }
        return count>(numbers.size()>>1)?res:0;
    }
};