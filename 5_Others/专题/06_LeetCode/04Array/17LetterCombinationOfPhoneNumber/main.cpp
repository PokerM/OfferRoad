#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {


        vector<string> output;
        unordered_map<char,vector<string>> num2char;

        num2char['2'] = vector<string> {"a", "b", "c"};
        num2char['3'] = vector<string> {"d", "e", "f"};
        num2char['4'] = vector<string> {"g", "h", "i"};
        num2char['5'] = vector<string> {"j", "k", "l"};
        num2char['6'] = vector<string> {"m", "n", "o"};
        num2char['7'] = vector<string> {"p", "q", "r", "s"};
        num2char['8'] = vector<string> {"t", "u", "v"};
        num2char['9'] = vector<string> {"w", "x", "y", "z"};


        int i = 0;
        while(digits[i] == '1'){
            i++;
        }
        output = num2char[digits[i]]; // Save first digit characters if 1st digit is not 1
        i++;
        for(; i < digits.length(); i++)
        {
            if(digits[i] == '1')
                continue;
            else
            {
                vector<string> s; //Temp vector
                s = num2char[digits[i]];
                vector<string> out = output;
                output.clear();

                for(int j = 0 ; j<out.size(); j++)
                {
                    string temp = out[j];

                    for(int k = 0; k<s.size(); k++)
                    {
                        string t = temp + s[k];
                        output.emplace_back(t);
                    }
                }
            }
        }

        return output;
    }
};
int main()
{
    Solution so;

    return 0;
}
