#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct Node {
        int degree;//节点深度
        int edge;//边
    };
    
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        if (n == 1) {
            return {0};
        }
        
        vector<Node> nodes(n, Node{0, 0});
        int nodeCount = n;
        
        for (const auto& p : edges) {
            nodes[p.first].degree++;
            nodes[p.first].edge ^= p.second;
            nodes[p.second].degree++;
            nodes[p.second].edge ^= p.first;
        }
        
        vector<int> u;
        vector<int> v;
        
        for (int i = 0; i < n; i++) {
            if (nodes[i].degree == 1) {
                u.push_back(i);//取出叶子节点
            }
        }
        //本质为从底至上的层序遍历，采用异或操作简化记录其所有子节点的操作，思考：用这种方式拿来存树这种结构非常有趣，假设总的节点为N，
        //那么，用这种结构需要2*N的空间
        while (nodeCount > 2) {
            for (const auto id : u) {//遍历叶子节点，然后判断其父节点是否只有其一个儿子
                const auto node = &nodes[id];
                const auto otherNode = &nodes[node->edge];
                nodeCount--;
                otherNode->degree--;
                otherNode->edge ^= id;
                if (otherNode->degree == 1) {
                    v.push_back(node->edge);//将该父节点放入新的叶子节点中
                }
            } 
            swap(u, v);
            v.clear();
        }
        
        return u;
    }
};

int main(){
    cout<<(1^1)<<endl;
    return 0;
}