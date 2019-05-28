#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>

using namespace std;

struct BinaryTreeNode{
    int                    val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
    BinaryTreeNode(int x):val(x),left(NULL),right(NULL){};
};
/*
二叉树的三种遍历方式：
1.前序遍历
2.中序遍历
3.后序遍历
*/

//1.前序遍历：访问顺序（中->左->右）
//递归实现
void rePreorderTraversal(BinaryTreeNode* root,vector<BinaryTreeNode*>& ve){
    if(root == NULL)return;
    ve.push_back(root);
    rePreorderTraversal(root->left,ve);
    rePreorderTraversal(root->right,ve);
}
//非递归实现
void preorderTraversal(BinaryTreeNode* root,vector<BinaryTreeNode*>& ve){
    if(root == NULL)return;
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* p = root;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            //判断当前节点是否为空
            //当前节点不为空，将该节点加入结果中并压入栈中，为后面访问该节点做准备
            ve.push_back(p);
            s.push(p);
            p = p->left;
        }
        else{
            //当前节点为空，查看上一次访问节点的右儿子
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

//2.中序遍历：遍历顺序(左->中->右)
//递归实现
void reInorderTraversal(BinaryTreeNode* root,vector<BinaryTreeNode*>& ve){
    if(root == NULL)return;
    reInorderTraversal(root->left,ve); //先访问左子树
    ve.push_back(root);                //中间节点
    reInorderTraversal(root->right,ve);//最后访问右子树
    return;
}
//非递归实现
void inorderTraversal(BinaryTreeNode* root,vector<BinaryTreeNode*>& ve){
    if(root == NULL)return;
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* p = root;
    while(p != NULL || !s.empty()){
        if(p != NULL){//当前节点不为空，压入栈中，查看其左儿子节点
            s.push(p);
            p = p->left;
        }
        else{         //当前节点为空，查看上一次访问节点，将该节点加入结果中，并查看其右儿子
            p = s.top();
            ve.push_back(p);
            s.pop();
            p = p->right;
        }
    }
}

//后序遍历：遍历顺序(左->右->中)
//递归实现
void rePostOrderTraversal(BinaryTreeNode* root,vector<BinaryTreeNode*>& ve){
    if(root == NULL)return;
    rePostOrderTraversal(root->left,ve);//左
    rePostOrderTraversal(root->right,ve);//右
    ve.push_back(root);//中
}
//非递归实现
// void postOrderTraversal(BinaryTreeNode* root,vector<BinaryTreeNode*>& ve){
//     if(root == NULL)return;
//     BinaryTreeNode* p = root;
//     stack<BinaryTreeNode*> s;
//     set<BinaryTreeNode*> stack_set, node_set;
//     while(p != NULL || !s.empty()){
//         if(p != NULL){//当前节点不为空，压入栈中，继续查看其左儿子
//             if(stack_set.find(p)==stack_set.end()){
//                 s.push(p);
//                 stack_set.insert(p);
//                 p = p->left;
//             }
//             else
//                 p = p->right;
//         }
//         else{         //当前节点为空，查看上一次访问节点
//             p = s.top();
//             if(p->right == NULL|| node_set.find(p) != node_set.end()){
//                 s.pop();
//                 ve.push_back(p);
//                 if(s.empty())break;
//                 p = s.top();
//             }
//             else{
//                 node_set.insert(p);
//                 p = p->right;
//             } 
//         }
//     }
// }

//非递归实现 v2
void postOrderTraversal(BinaryTreeNode* root,vector<BinaryTreeNode*>& ve){
    if(root == NULL)return;
    BinaryTreeNode* p = root;
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* pre = NULL;
    s.push(p);
    while(!s.empty()){
        p = s.top();
        if((p->left == NULL && p->right == NULL) ||
            (pre != NULL && (pre == p->left || pre == p->right))){//当前节点没有左右儿子或者左右儿子已经被加入到ve中
            ve.push_back(p);
            pre = p;
            s.pop();
        }
        else{                                                     //当前节点还有儿子节点没有加入到结果中，栈中所有节点都在儿子节点下面，右节点都在左节点下面，保证了顺序         
            if(p->right != NULL)s.push(p->right);
            if(p->left != NULL)s.push(p->left); 
        }
    }
}

//BFS
void BFS(BinaryTreeNode* root, vector<BinaryTreeNode*>& ve){
    if(root == NULL)return;
    queue<BinaryTreeNode*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode* c = q.front();
        q.pop();
        ve.push_back(c);
        if(c->left != NULL)q.push(c->left);
        if(c->right != NULL)q.push(c->right);
    }
    return;
}

//DFS
// void DFS(BinaryTreeNode* root, vector<BinaryTreeNode*>& ve){
//     if(root == NULL)return;
//     ve.push_back(root);
//     DFS(root->left, ve);
//     DFS(root->right, ve);
//     return;
// }

//DFS v2
void DFS(BinaryTreeNode* root, vector<BinaryTreeNode*>& ve){
    if(root == NULL)return;
    ve.push_back(root);
    stack<BinaryTreeNode*> s;
    s.push(root);
    BinaryTreeNode* p = root->left;
    while(p != NULL || !s.empty()){
        if(p != NULL){
            ve.push_back(p);
            s.push(p);
            p = p->left;
        }
        else{
            p = s.top()->right;
            s.pop();
        }
    }
}

//重建二叉树：利用前序遍历时，总是优先遍历根节点的特点，中序遍历时，根节点左边为左子树，右边为右子树的特点，逐层重建二叉树。
class Solution {
public:
    //s0:前序遍历的当前节点;s1,e1:中序遍历的起点和终点
    TreeNode* re(const vector<int>& pre,int s0, const vector<int>& vin, int s1, int e1){
        if(s1>e1)return NULL;
        TreeNode* p = new TreeNode(pre[s0]);
        if(s1==e1)return p;
        for(int i=s1;i<=e1;i++){
            if(vin[i]==pre[s0]){                          //找到该节点
                p->left = re(pre,s0+1,vin,s1,i-1);        //找到左儿子
                p->right = re(pre,s0+i-s1+1,vin,i+1,e1);  //找到右儿子,i-s1为左子树的所有节点的数目
                return p;
            }
        }
        return p;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty())return NULL;
        return re(pre,0,vin,0,vin.size()-1);
    }
};

int main(){
    struct BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->right->right = new BinaryTreeNode(6);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    struct BinaryTreeNode* p = root->left->right;
    p->left = new BinaryTreeNode(7);
    p->right = new BinaryTreeNode(8);
    vector<BinaryTreeNode*> ve;
    //preorderTraversal(root, ve);
    //inorderTraversal(root,ve);
    //postOrderTraversal(root,ve);
    //BFS(root, ve);
    DFS(root, ve);
    for(size_t i=0;i<ve.size();i++)cout<<ve[i]->val<<" ";
    cout<<endl;
    //cout<<"root "<<root->left->val;
    return 0;
}