class Solution {
    //返回从根节点到叶节点最大，其中re保存当前树的最大路径和
    int maxToRoot(TreeNode *root, int &re) {
        if (!root) return 0;
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        if (l + r + root->val > re) re = l + r + root->val;
        return root->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = INT32_MIN;
        maxToRoot(root, max);
        return max;
    }
};

class Solution {
private:
    int maxSize;
public:
    void re(string& s, unordered_set<string>& word_set, vector<vector<string>>& res, int start){
        if(!res[start].empty())return;
        for(int i=1;i<=maxSize;++i){
            if(start+i>s.size())break;
            string sub = s.substr(start, i);
            if(word_set.find(sub)!=word_set.end()){
                if(start + i == s.size()){
                    res[start].push_back(sub);
                }
                else{
                    re(s, word_set, res, start + i);
                    for(auto &si : res[start+i]){
                        auto t = sub;
                        t.append(" ");
                        t.append(si);
                        res[start].push_back(t);
                    }
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        maxSize = 0;
        for(auto &word : wordDict)maxSize = maxSize < word.size()?word.size():maxSize;
        vector<vector<string>> res(s.size(), vector<string>());
        re(s, word_set, res, 0);
        return res[0];
    }
};