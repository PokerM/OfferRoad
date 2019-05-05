//算法分析：T(n) = 1 + T(3n/4),那么时间复杂度为以4/3为底的对数
//剑指offer给出的算法可能出现非常差的时间复杂度：考虑二维数组退化成一维数组，那么书上的算法则退化为n,没有利用有序性，所以不是最优的算法
class Solution {
public:
    bool find_re(int target, vector<vector<int> >& array, int s0, int s1, int e0, int e1){
        if(array[s0][s1]>target||array[e0][e1]<target){//左上角元素(最小)大于目标元素，或者右下角元素(最大)小于目标元素
            cout<<"array["<<s0<<"]["<<s1<<"]="<<array[s0][s1]<<" array["<<e0<<"]["<<e1<<"]="<<array[e0][e1]<<endl;
            return false;
        }
        if(array[s0][s1]==target||array[e0][e1]==target)return true;//边界检测
        if(s0<e0-1||s1<e1-1){
            int mid0 = (s0+e0)>>1;
            int mid1 = (s1+e1)>>1;
            if(array[mid0][mid1]==target)return true;
            if(array[mid0][mid1]<target)//中间元素小于目标值，丢弃掉左上角分块
                return find_re(target,array,mid0,mid1,e0,e1)||
                       find_re(target,array,s0,mid1,mid0,e1)||
                       find_re(target,array,mid0,s1,e0,mid1);
            else//中间元素大于目标值，丢弃掉右下角分块
                return find_re(target,array,s0,s1,mid0,mid1)||
                       find_re(target,array,s0,mid1,mid0,e1)||
                       find_re(target,array,mid0,s1,e0,mid1);
        }
        else{
            return false;
        }
    }
    bool Find(int target, vector<vector<int> > array) {
        int w,l;
        l = array.size();
        if(l==0)return false;
        w = array[0].size();
        if(w==0)return false;
        return find_re(target,array,0,0,l-1,w-1);
    }
};