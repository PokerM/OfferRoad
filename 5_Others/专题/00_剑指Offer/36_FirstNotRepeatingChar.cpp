//时间复杂度N
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> mp;
        for(int i = 0; i < str.size(); ++i)
            mp[str[i]]++;
        for(int i = 0; i < str.size(); ++i){
            if(mp[str[i]]==1)
                return i;
        }
        return -1;
    }
};