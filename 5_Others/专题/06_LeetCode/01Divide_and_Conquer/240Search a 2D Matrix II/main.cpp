#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findUPLocation(vector<int> vec, int target){
        if(target < vec.front())return -1;
        if(target > vec.back())return vec.size();
        if(target == vec.front() || target == vec.back())return 0;
        int length = vec.size();
        int start = 0, end = length - 1;
        while(length > 2){
            int mid = (end + start) >> 1;
            if(vec[mid] == target)return 0;
            if(vec[mid] > target)
                end = mid;
            else
                start = mid;
            length = end - start + 1;
        }
        return start+1;
    }
    int findLOWLocation(vector<int> vec, int target){
        if(target < vec.front())return 1;
        if(target > vec.back())return -1;
        if(target == vec.front() || target == vec.back())return 0;
        int length = vec.size();
        int start = 0, end = length - 1;
        while(length > 2){
            int mid = (end + start) >> 1;
            if(vec[mid] == target)return 0;
            if(vec[mid] > target)
                end = mid;
            else
                start = mid;
            length = end - start + 1;
        }
        return end+1;
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()<1||matrix[0].size()<1)return false;
        if(corner.size()<1){
            corner.push_back(0);
            corner.push_back(matrix[0].size()-1);
            corner.push_back(0);
            corner.push_back(matrix.size()-1);
        }
        while(1){
            int width = corner[1]-corner[0]+1;
            int height = corner[3]-corner[2]+1;
            if(width<0||height<0)return false;
            vector<int> vec1(width),vec2(width),vec3(height),vec4(height);
            for(int i=0;i<width;i++){
                vec1[i]=matrix[corner[2]][corner[0]+i];
                vec2[i]=matrix[corner[3]][corner[0]+i];
            }
            for(int j=0;j<height;j++){
                vec3[j]=matrix[corner[2]+j][corner[0]];
                vec4[j]=matrix[corner[2]+j][corner[1]];
            }
            int res1 = findUPLocation(vec1, target);
            int res2 = findLOWLocation(vec2, target);
            int res3 = findUPLocation(vec3, target);
            int res4 = findLOWLocation(vec4, target);
            if(res1==-1||res2==-1||res3==-1||res4==-1)return false;
            if(res1&&res2&&res3&&res4){
                if((res1-res2)<0||(res3-res4)<0||(res1-res2)<=1&&(res3-res4)<=1){
                    return false;
                }
                vector<int> temp(4);
                int a,b;
                a = corner[0];
                b = corner[2];
                corner[0]=a+res2-1;
                corner[1]=a+res1-1;
                corner[2]=b+res4-1;
                corner[3]=b+res3-1;
            }
            else
                return true;
        }
    }
private:
    vector<int> corner;
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
    vector<vector<int> > temp(1,vector<int>(2,1));
    //for(int i=0;i<matrix.size();i++)matrix[i]=i;
    //cout<<matrix[1].at(1);
//    cout<<temp[0][0]<<" "<<temp[0][1]<<endl;
    bool res = so.searchMatrix(matrix, 20);
    return res;
}
