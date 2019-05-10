//中序（左中右）遍历的下一节点：
//1)若当前节点存在右子树，则返回右子树的最左叶子节点
//2)若当前节点不存在右子树，则往上查看当前节点的父节点，直到该节点是父节点的左儿子
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == nullptr)return pNode;
        if(pNode->right != nullptr){
            TreeLinkNode* p = pNode->right;
            while(p->left != nullptr)p = p->left;
            return p;
        }
        TreeLinkNode* p = pNode;
        TreeLinkNode* parent = pNode->next;
        while(parent != nullptr){
            if(parent->left == p)return parent;
            p = parent;
            parent = parent->next;
        }
        return nullptr;
    }
};