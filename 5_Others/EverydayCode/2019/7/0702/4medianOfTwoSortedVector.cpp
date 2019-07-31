//基本思路：中位数就是将数组平均分成两部分的数，左边比该数小，右边比该数大
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, m = nums1.size(), n = nums2.size();
        //处理为某个数组为空的情况
        if(m==0)return n%2?nums2[n/2] : (nums2[n/2]+nums2[n/2-1])/2.0;
        if(n==0)return m%2?nums1[m/2] : (nums1[m/2]+nums1[m/2-1])/2.0;
        for(;i<=m;++i){
            j = (m + n) / 2 - i;//计算平均分成两部分对应下标
            if(j<0||j>n)continue;
            if((i==0||j==n||nums1[i-1]<=nums2[j])&&(j==0||i==m||nums2[j-1]<=nums1[i]))break;//满足左右两部分大小关系
        }
        int max_of_left, min_of_right;
        //处理边界条件
        if(i==0)max_of_left = nums2[j-1];
        else if(j==0)max_of_left = nums1[i-1];
        else max_of_left = max(nums1[i-1], nums2[j-1]);

        if(i==m)min_of_right = nums2[j];
        else if(j==n)min_of_right = nums1[i];
        else min_of_right = min(nums1[i], nums2[j]);

        cout<<i<<" "<<j<<endl;
        return (m+n)%2?min_of_right : (max_of_left + min_of_right) / 2.0;
    }
};