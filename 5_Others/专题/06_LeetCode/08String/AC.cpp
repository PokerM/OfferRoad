#include <iostream>
#include <memory>
#include <string>
#include <stack>
#include <queue>

using namespace std;
class Trie{
public:
    struct Node{
        shared_ptr<Node> child[26];
        weak_ptr<Node> fail;
        bool isWord;
        size_t count;
        Node():isWord(false),count(0){
        }
    };
    Trie() : root(new Node){
    }
    void insert(string&& s){
        auto p = root;
        for(auto i : s){
            if(p->child[i-'a']==nullptr)p->child[i-'a'].reset(new Node);
            p = p->child[i-'a'];
            p->count++;
        }
        p->isWord = true;
    }
    void print(){
        auto p = root;
        string s;
        dfs(p, s);
    }
    void dfs(shared_ptr<Node> p, string& s){
        if(p == nullptr)return;
        if(p->isWord)cout<<s<<endl;
        for(int i=0;i<26;i++){
            if(p->child[i]!=nullptr){
                s.push_back('a'+i);
                dfs(p->child[i], s);
                s.pop_back();
            }
        }
    }
    bool contain(string&& s){
        contain(s);
    }
    bool contain(string& s){
        auto p = root;
        for(auto i : s){
            if(p->child[i-'a']==nullptr)return false;
            p = p->child[i-'a'];
        }
        return p->isWord;
    }
    bool remove(string&& s){
        if(!contain(s))return false;
        auto p = root;
        stack<shared_ptr<Node>> stack;
        for(auto i : s){
            p = p->child[i-'a'];
            if(--(p->count)==0)stack.push(p);
        }
        p->isWord = false;
        while(!stack.empty()){
            auto p = stack.top();
            p.reset();
            stack.pop();
        }
        return true;
    }
    void getFail(){
        queue<shared_ptr<Node>> q;
        auto p = root;
        p->fail = root;
        for(int i=0;i<26;i++){
            if(p->child[i]){
                p->child[i]->fail = root;
                q.push(p->child[i]);
            }
        }
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(t->child[i]){
                    auto t_fail = t->fail.lock();
                    if(t_fail->child[i]){
                        t->child[i]->fail = t_fail->child[i];
                    }
                    else t->child[i]->fail = root;
                    q.push(t->child[i]);
                }
            }
        }
    }
    int query(string&& s){
        auto p = root;
        int res = 0;
        int i = 0;
        while(i < s.size()){
            if(p->child[s[i]-'a']==nullptr){
                if(p == root)//返回到根节点，略过当前字符
                    i++;
                else
                    p = p->fail.lock();//返回其失败节点
            }
            else{
                p = p->child[s[i]-'a'];
                cout<<"find "<<s[i]<<endl;
                // if(s[i]=='n'){
                //     cout<<"is word "<<p->isWord<<endl;
                // }
                if(p->isWord){
                    cout<<"find word "<<s[i]<<endl;
                    res++;
                }
                i++;
            }
        }
        return res;
    }
private:
    struct shared_ptr<Node> root;
};

int main(){
    Trie trie;
    trie.insert(string("duan"));
    trie.insert(string("xian"));
    trie.insert(string("duqiang"));
    trie.getFail();
    trie.print();
    cout<<trie.query(string("xduanxianduqiang"));
    // cout<<trie.contain(string("qiang"))<<endl;
    // cout<<trie.contain(string("duan"))<<endl;
    // cout<<trie.remove(string("duan"))<<endl;
    // cout<<trie.contain(string("duan"))<<endl;
    return 0;
}