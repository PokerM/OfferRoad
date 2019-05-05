class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getDepth(pRoot) != -1;
    }
private: 
    //不平衡返回-1，平衡返回树的高度
    int getDepth(TreeNode* root){
        if(root == NULL)return 0;
        int left = getDepth(root->left);
        if(left == -1)return -1;
        int right = getDepth(root->right);
        if(right == -1)return -1;
        return abs(left - right)>1?-1:1+max(left,right);
    }
};