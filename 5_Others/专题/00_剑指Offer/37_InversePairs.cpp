class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size()<2)return 0;
        vector<int> copy(data);
        return reInversePairs(data, copy, 0, data.size()-1);
    }
    int reInversePairs(vector<int>& data, vector<int>& copy, int start, int end){
        if(start>end)return 0;
        if(start==end){
            copy[start] = data[start];
            return 0;
        }
        int mid = (start + end)>>1;
        int left = reInversePairs(copy,data,start,mid);//左侧逆序对，
        int right = reInversePairs(copy,data,mid+1,end);//右侧逆序对
        int p1 = mid, p2 = end, p3 = end;
        int res = 0;
        while(p1>=start && p2 > mid){
            if(data[p1] > data[p2]){
                copy[p3--] = data[p1--];
                res = (res + p2 - mid)%1000000007; 
            }
            else{
                copy[p3--] = data[p2--];
            }
        }
        while(p2>mid){
            copy[p3--] = data[p2--];
        }
        while(p1>=start){
            copy[p3--] = data[p1--];
        }
        return (left + right + res)%1000000007;
    }
};