class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() == 0 || s.size() < t.size()) return "";
        vector<int> remaining(128, 0);//各符号计数器
        int required = t.size();//总共需要的字符数
        for (int i = 0; i < required; ++i) ++remaining[t[i]];//统计各个符号数量
        
        // left is the start index of the min-length substring ever found
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while(i <= s.size() && start < s.size()) {
            if(required) {//还需要更多的字符
                if (i == s.size()) break;
                --remaining[s[i]];//对应需要字符数量减小
                if (remaining[s[i]] >= 0) --required;//总共需求字符数减一
                ++i;//标兵前移
            } else {//不需要更多字符
                if (i - start < min) {//更优解
                    min = i -start;
                    left = start;
                }
                //去掉起始位置，尝试更优解
                ++remaining[s[start]];
                if (remaining[s[start]] > 0) ++required;//字符不够
                ++start;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};

//我的做法
class Solution {
public:
    string minWindow(string s, string t) {
        //基本思路：左右两个标兵控制一个移动窗口，用一个vector来统计需要的各个字符数量，一个总的计数器来统计总的需要字符
        //两步：
        /*
        第一步：将右边标兵往前移，直到窗口满足要求，更新结果
        第二步：将左边标兵往前移，直到窗口不满足要求，返回第一步
        注意边界条件
         */
        if(t.empty()||s.size()<t.size())return "";
        int left = 0, right = 0, count = 0, start = 0;
        count = t.size();
        vector<int> remain(128, 0);
        for(auto i : t)++remain[i];
        int min = INT32_MAX;
        while(left < s.size() && right <= s.size()){
            //窗口不满足要求，前移右标兵
            if(count){
                if(right==s.size())break;
                if(--remain[s[right++]] >= 0)--count;
            }
            //窗口满足要求，前移左标兵
            if(!count){
                if(right - left < min){
                    min = right - left ;
                    start = left;
                }
                if(++remain[s[left++]]>0)++count;
            }
        }
        return min==INT32_MAX?"":s.substr(start, min);
    }
};