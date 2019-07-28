#include <iostream>

using namespace std;
class Solution {
public:
    bool isEqual(char a, char b){
        if(a=='(' && b==')')return true;
        if(a=='{' && b=='}')return true;
        if(a=='[' && b==']')return true;
        return false;
    }
    bool isValid(string s) {
        string::iterator start=s.begin(), end=s.end();

        while(start!=end&&start-end<0){
            if(!isEqual(*start, *end))return false;
            start++;
            end--;
        }
        return true;
    }
};
int main()
{
    Solution so;
    return so.isValid("(]");
}
