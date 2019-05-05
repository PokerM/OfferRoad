class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())return 0;
        int res;
        int i=0;
        bool na = false;
        if(str[0]=='-'){
            na = true;
            i++;
        }
        else if(str[0]=='+'){
            i++;
        }
        if(str[i]<='9'&&str[i]>'0')
            res = str[i]-'0';
        else
            return 0;
        i++;
        while(str[i]!='\0'){
            if(str[i]<='9'&&str[i]>='0')
                res = res*10+str[i]-'0';
            else
                return 0;
            i++;
        }
        return na?-1*res:res;
    }
};