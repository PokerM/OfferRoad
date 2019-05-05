//中序遍历，递归版
class Solution {
public:
    int count;
    TreeNode* reKthNode(TreeNode* pRoot){
        if(pRoot==NULL)return NULL;
        TreeNode* res = reKthNode(pRoot->left);
        if(res != NULL) return res;
        count--;
        if(count == 0)return pRoot;
        res = reKthNode(pRoot->right);
        if(res != NULL) return res;
        return NULL;
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(k==0)return NULL;
        count = k;
        return reKthNode(pRoot);
    }
};

//非递归实现
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(k==0 || pRoot == NULL)return NULL;
        stack<TreeNode*> s;
        TreeNode* p = pRoot;
        while(p != NULL || !s.empty()){
            if(p != NULL){
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                if(--k == 0)return p;
                s.pop();
                p = p -> right;
            }
        }
        return NULL;
    }
};