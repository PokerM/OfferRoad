//space(N),time(size+n)
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n==0||n==str.size()||str.empty())return str;
        n = n % str.size();
        char t[n];
        for(int i=0;i<n;i++){
            t[i] = str[i];
        }
        for(int i=0;i<str.size()-n;i++){
            str[i] = str[i+n];
        }
        for(int i=0;i<n;i++){
            str[str.size()-n+i] = t[i];
        }
        return str;
    }
};
//version2 
//space(1)，time(size+n)
class Solution {
public:
    string LeftRotateString(string str, int n) 
    {
      int len = str.size();
        if(len == 0) return str;
        n %= len;
        for(int i = 0, j = n - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = n, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        for(int i = 0, j = len - 1; i < j; ++i, --j) swap(str[i], str[j]);
        return str;
    }
};