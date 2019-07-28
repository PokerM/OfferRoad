#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <functional>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> my_map;
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            my_map.insert(pair<int,int>(nums1[i],0));
        }
        for(int i=0;i<nums2.size();i++){
            if(my_map.find(nums2[i])!=my_map.end())
                res.push_back(nums2[i]);
        }
        set<int> temp(res.begin(),res.end());
        res.assign(temp.begin(),temp.begin());
        return res;
    }
};
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}
int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);
        vector<int> ret = Solution().intersection(nums1, nums2);
    }
    return 0;
}
