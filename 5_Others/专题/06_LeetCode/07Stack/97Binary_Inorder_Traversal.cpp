/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)return {};
        
        TreeNode* curNode = root;
        vector<int> inorderVe;
        stack<TreeNode> nodeStack;
        while(curNode != nullptr || !nodeStack.empty()){
            while(curNode != nullptr){
                nodeStack.push(*curNode);
                curNode = curNode->left;
            }
            TreeNode tmp = nodeStack.top();
            curNode = tmp.right;
            nodeStack.pop();
            inorderVe.push_back(tmp.val);
        }
        return inorderVe;
    }
};