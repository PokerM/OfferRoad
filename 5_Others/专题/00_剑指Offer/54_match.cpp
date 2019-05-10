/*
*/

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str[0]=='\0'){
            if(pattern[0]=='\0')return true;
            if(pattern[1]=='*')return match(str,pattern+2);
            return false;
        }
        if(str[0]==pattern[0]||pattern[0]=='.'){
            if(pattern[1]=='*'){
                bool res = match(str, pattern + 2)||match(str+1, pattern+2);//0次和1次
                if(res)return true;
                int i=1;
                while(str[i]!='\0'&&(pattern[0]=='.'||str[i-1]==str[i])){//匹配多次
                    if(match(str+i+1,pattern+2))return true;
                    i++;
                }
                return false;
            }
            return match(str+1,pattern+1);//匹配下一个字符
        }
        //当前字符不相等
        if(pattern[0]=='\0')return false;
        if(pattern[1]=='*')return match(str,pattern+2);
        return false;
    }
};