//依次访问矩阵中元素，一旦找到与首字符相等的字符，那么依次访问其上下左右四个方向的字符，用set存放访问过的下标
class Solution {
public:
    bool reHasPath(char* matrix, int rows, int cols, char* str, unordered_set<int>& loaded_char, int x, int y, int ptr){
        if(str[ptr]=='\0')return true;//走到字符串尾
        //往上
        if(y+1<rows&&matrix[(y+1)*cols+x]==str[ptr]&&loaded_char.find((y+1)*cols+x)==loaded_char.end()){
            loaded_char.insert((y+1)*cols+x);
            if(reHasPath(matrix,rows,cols,str,loaded_char,x,y+1,ptr+1))
                return true;
        }
        //往下
        if(y-1>=0&&matrix[(y-1)*cols+x]==str[ptr]&&loaded_char.find((y-1)*cols+x)==loaded_char.end()){
            loaded_char.insert((y-1)*cols+x);
            if(reHasPath(matrix,rows,cols,str,loaded_char,x,y-1,ptr+1))
                return true;
        }
        //往左
        if(x-1>=0&&matrix[y*cols+x-1]==str[ptr]&&loaded_char.find(y*cols+x-1)==loaded_char.end()){
            loaded_char.insert(y*cols+x-1);
            if(reHasPath(matrix,rows,cols,str,loaded_char,x-1,y,ptr+1))
                return true;
        }
        //往右
        if(x+1<cols&&matrix[y*cols+x+1]==str[ptr]&&loaded_char.find(y*cols+x+1)==loaded_char.end()){
            loaded_char.insert(y*cols+x+1);
            if(reHasPath(matrix,rows,cols,str,loaded_char,x+1,y,ptr+1))
                return true;
        }
        loaded_char.erase(y*cols+x);
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(str[0]=='\0')return true;
        unordered_set<int> loaded_char;//存放已经访问过的下标
        for(int i=0;i<cols;i++){
            for(int j=0;j<rows;j++){
                if(matrix[j*cols+i]==str[0]){
                    loaded_char.insert(j*cols+i);
                    if(reHasPath(matrix,rows,cols,str,loaded_char,i,j,1))return true;
                }
            }
        }
        return false;
    }
};