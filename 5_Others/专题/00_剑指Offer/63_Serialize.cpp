#include <vector>

using namespace std;

typedef TreeNode node;
typedef TreeNode* pnode;
typedef int* pint;
class Solution {
    vector<int> buf;
    void dfs(pnode p){
        if(!p) buf.push_back(0x23333);
        else{
            buf.push_back(p -> val);
            dfs(p -> left);
            dfs(p -> right);
        }
    }
    pnode dfs2(pint& p){
        if(*p == 0x23333){
            ++p;
            return NULL;
        }
        pnode res = new node(*p);
        ++p;
        res -> left = dfs2(p);
        res -> right = dfs2(p);
        return res;
    }
public:
    char* Serialize(TreeNode *p) {
        buf.clear();
        dfs(p);
        int *res = new int[buf.size()];
        for(unsigned int i = 0; i < buf.size(); ++i) res[i] = buf[i];
        return (char*)res;
    }
    TreeNode* Deserialize(char *str) {
        int *p = (int*)str;
        return dfs2(p);
    }
};