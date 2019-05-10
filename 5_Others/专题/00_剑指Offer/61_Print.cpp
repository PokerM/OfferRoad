#include <vector>

using namespace std;

//之字形打印
//层序打印，偶数层逆序
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot == NULL)return vector<vector<int> >();
        bool even = false;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(pRoot);
        vector<vector<int> > res;
        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            vector<int> tmp;
            for(size_t i=0;i<size;i++){
                auto p = nodeQueue.front();
                nodeQueue.pop();
                tmp.push_back(p->val);
                if(p->left)nodeQueue.push(p->left);
                if(p->right)nodeQueue.push(p->right);
            }
            if(even)
                reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            even = !even;
        }
        return res;
    }
};