class Solution {
private:
    vector<vector<int> >allRes;
    vector<int> tmp;
    void dfsFind(TreeNode * node , int left){
        tmp.push_back(node->val);
        if(left-node->val == 0 && !node->left && !node->right)//找到该路径，且当前节点为叶子节点
            allRes.push_back(tmp);
        else {
            if(node->left) dfsFind(node->left, left-node->val);
            if(node->right) dfsFind(node->right, left-node->val);
        }
        tmp.pop_back(); 
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root != NULL) dfsFind(root, expectNumber);
        return allRes;
    }
};