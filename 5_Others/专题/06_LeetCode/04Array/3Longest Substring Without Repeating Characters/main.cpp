#include <iostream>
#include <map>
#include <string>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> my_map;
        int max_size=0;
        int str_size=s.size();
        int s_p=0,c_p=0;
        string::iterator it=s.begin();
        int cur_size=0;
        map<char,int>::iterator it_map;
        while(cur_size+str_size>max_size){
            it_map=my_map.find(*it);
            if(it_map==my_map.end()){
                cur_size=c_p-s_p+1;
                if(cur_size>max_size)max_size=cur_size;
                my_map.insert(pair<char,int>(*it,c_p));
            }
            else if(it_map->second<s_p){
                cur_size=c_p-s_p+1;
                if(cur_size>max_size)max_size=cur_size;
                it_map->second=c_p;
            }
            else{
                s_p=it_map->second+1;
                it_map->second=c_p;
            }
            c_p++;
            it++;
            str_size--;
        }
        return max_size;
    }
};
int main()
{
    Solution so;
    int res = so.lengthOfLongestSubstring("bbbbb");
    cout<<res<<endl;
    return 0;
}
