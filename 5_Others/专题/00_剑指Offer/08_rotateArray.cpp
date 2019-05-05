//二分查找的变种
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())return 0;
        if(rotateArray.size()==1)return rotateArray[0];
        int s=0,e=rotateArray.size()-1,m;
        while(rotateArray[s] == rotateArray[e])e--;//考虑特殊情况：2,3,5,2,2,2，
        if(rotateArray[s]<rotateArray[e])return rotateArray[0];
        while(s < e - 1){
            m = (s + e) >> 1;
            if(rotateArray[m] >= rotateArray[s])
                s = m;
            else
                e = m;
        }
        return rotateArray[e];
    }
};