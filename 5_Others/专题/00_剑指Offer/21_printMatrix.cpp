class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.empty()||matrix[0].empty())return vector<int>();
        int height = matrix.size();
        int width = matrix[0].size();
        int a = 0;
        int i=0,j=0;
        vector<int> res;
        while(height>0&&width>0){
            switch(a){
                case 0://从左往右
                    for(int k=0;k<width;k++){
                        res.push_back(matrix[i][j]);
                        j++;
                    }
                    j--;
                    i++;
                    height--;
                    a++;
                    break;
                case 1://从上往下
                    for(int k=0;k<height;k++){
                        res.push_back(matrix[i][j]);
                        i++;
                    }
                    i--;
                    j--;
                    width--;
                    a++;
                    break;
                case 2://从左往右
                    for(int k=0;k<width;k++){
                        res.push_back(matrix[i][j]);
                        j--;
                    }
                    j++;
                    i--;
                    height--;
                    a++;
                    break;
                default://从下往上
                    for(int k=0;k<height;k++){
                        res.push_back(matrix[i][j]);
                        i--;
                    }
                    i++;
                    j++;
                    width--;
                    a=0;
                    break;
            }
        }
        return res;
    }
};