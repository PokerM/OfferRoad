/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//层序遍历
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(root==NULL)return vector<int>();
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while(!q.empty()){
            res.push_back(q.front()->val);
            if(q.front()->left!=NULL)q.push(q.front()->left);
            if(q.front()->right!=NULL)q.push(q.front()->right);
            q.pop();
        }
        return res;
    }
};