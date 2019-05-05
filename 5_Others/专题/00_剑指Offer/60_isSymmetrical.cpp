class Solution {
public:
    bool comRoot(TreeNode* left, TreeNode* right){
        if(left==NULL)return right==NULL;
        if(right==NULL)return false;
        if(left->val!=right->val)return false;
        return comRoot(left->right,right->left)&&comRoot(left->left,right->right);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)return true;//处理空树的情况
        return comRoot(pRoot->left,pRoot->right);//返回左右子树是否对称
    }
};