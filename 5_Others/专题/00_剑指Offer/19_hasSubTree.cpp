/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL||pRoot2==NULL)return false;
        if(pRoot1->val==pRoot2->val)//当前节点相等，可能为子树
            //判断相等节点对应的树是否为子树，或者是别的可能
            return subTree(pRoot1->left,pRoot2->left)&&subTree(pRoot1->right,pRoot2->right)
                    ||HasSubtree(pRoot1->left,pRoot2)
                    ||HasSubtree(pRoot1->right,pRoot2);
        return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);//当前节点不相等，则只可能在左子树或者右子树中可能存在子树
    }
    bool subTree(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2==NULL)return true;
        if(pRoot1==NULL)return false;
        if(pRoot1->val==pRoot2->val)return subTree(pRoot1->left,pRoot2->left)&&
                                           subTree(pRoot1->right,pRoot2->right);
        return false;
    }
};