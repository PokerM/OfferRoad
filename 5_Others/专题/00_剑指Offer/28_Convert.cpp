/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//中序遍历：先左再中再右
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)return NULL;
        if(pRootOfTree->left==NULL&&pRootOfTree->right==NULL){
            return pRootOfTree;
        }

        TreeNode* left = Convert(pRootOfTree->left);//左子树转换结果

        TreeNode* p = left;
        while(p != NULL&&p->right != NULL){
            p = p->right;
        }
        if(p!=NULL){
            p->right = pRootOfTree;
            pRootOfTree->left = p;
        }
        TreeNode* right = Convert(pRootOfTree->right);//右子树转换结果
        if(right!=NULL){
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        return left!=NULL?left:pRootOfTree;
    }
};