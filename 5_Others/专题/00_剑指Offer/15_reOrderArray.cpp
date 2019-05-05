//另外一种实现方法：不用额外空间，第一次遍历数组，得到奇数个数。然后两个哨兵（i=0,j=奇数个数），i找到偶数，j找到奇数，交换两个哨兵指向的数，直到遍历完
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int p=0,q=0;
        int len = array.size();
        int odd_num = 0;
        stack<int> s;
        int j=0;
        for(int i=0;i<len;i++){
            if((array[i]&1)==1){
                array[j] = array[i];
                j++;
            }
            else{
                s.push(array[i]);
            }
        }
        while(!s.empty()){
            len--;
            array[len]=s.top();
            s.pop();
        }
        return;
    }
};