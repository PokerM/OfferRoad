#include <iostream>
#include <vector>

using namespace std;
bool searchMatrix_divide_conquer(vector< vector<int> > &matrix, int target, int a, int b, int c, int d){
        if(a==b&&b==c&&c==d){
            if(matrix[a][a]==target)return true;
            else return false;
        }
        int wide_center,height_center;
        wide_center = (a+b)>>1;
        height_center = (c+d)>>1;
        int center = 0;
        vector<vector<int> > matrix1(5);
        int a1[]={1,4,7,11,15,2,5,8,12,19,3,6,9,16,22,10,13,14,17,24,18,21,23,26,30};
        for(int i=0;i<5;i++){
            vector<int> temp(5);
            for(int j=0;j<5;j++){
                temp[j]=a1[i*5+j];
            }
            matrix1[i] = temp;
        }
        if(center==target)return true;
        if(center<target){
            bool b1,b2,b3;

            b1 = searchMatrix_divide_conquer(matrix1,target,wide_center, b, c,d);
            b2 = searchMatrix_divide_conquer(matrix1,target,a, wide_center, height_center, d);
            b3 = searchMatrix_divide_conquer(matrix1,target,wide_center, b, height_center, d);
            return (b1||b2||b3);
        }
        else{
            return (searchMatrix_divide_conquer(matrix1,target,wide_center, b, c,d)||
                searchMatrix_divide_conquer(matrix1,target,a, wide_center, height_center, d)||
                searchMatrix_divide_conquer(matrix1,target,a, wide_center, c, height_center));
        }
    }
class Solution {
public:

//        return 0;

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()<1||matrix[0].size()<1)return false;
//        return searchMatrix_divide_conquer(matrix, target, 0,matrix[0].size()-1,0,matrix.size()-1);
    }
};
int main()
{
    Solution so;
    vector<vector<int> > matrix(5);
    int a[]={1,4,7,11,15,2,5,8,12,19,3,6,9,16,22,10,13,14,17,24,18,21,23,26,30};
    for(int i=0;i<5;i++){
        vector<int> temp(5);
        for(int j=0;j<5;j++){
            temp[j]=a[i*5+j];
        }
        matrix[i] = temp;
    }
    bool res = so.searchMatrix(matrix, 20);
    return res;
}
