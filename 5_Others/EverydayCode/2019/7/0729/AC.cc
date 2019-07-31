#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <queue>

using namespace std;

class AC{
private:
    typedef struct Node{
        shared_ptr<Node> child[26];
        weak_ptr<Node> fail;
        bool isWord;
        Node():isWord(false){
        }
    }Node;
    shared_ptr<Node> root;
public:
    AC(): root(new Node){
        
    }
    void insert(string&& s){
        insert(s);
    }
    void insert(string& s){
        if(!contain(s)){
            auto p = root;
            for(auto i : s){
                if(p->child[i-'a'] == nullptr)p->child[i-'a'].reset(new Node);
                p = p->child[i-'a'];
            }
            p->isWord = true;
        }
    }
    bool contain(string&& s){
        contain(s);
    }
    bool contain(string& s){
        auto p = root;
        for(auto i : s){
            if(!p->child[i-'a'])return false;
            p = p->child[i-'a'];
        }
        return p->isWord;
    }
    void getFail(){
        queue<shared_ptr<Node>> q;
        root->fail = root;
        for(int i=0;i<26;i++){
            if(root->child[i]){
                q.push(root->child[i]);
                root->child[i]->fail = root;
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
    int search(string&& s){
        search(s);
    }
    int search(string& s){
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
        // if(s.empty())return 0;
        // int i = 0;
        // int res = 0;
        // auto p = root;
        // while(i < s.size()){
        //     if(p->child[s[i]-'a']==nullptr){
        //         if(p == root){
        //             ++i;
        //             continue;
        //         }
        //         p = p->fail.lock();
        //     }
        //     else{
        //         p = p->child[s[i]-'a'];
        //         if(p->isWord){
        //             ++res;
        //             cout<<"find "<<s[i]<<endl;
        //             //p = p->fail.lock();
        //         }
        //         ++i;
        //     }
        // }
        // return res;
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

};
int main(){
    AC ac;
    ac.insert(string("duan"));
    ac.insert(string("xian"));
    ac.insert(string("qiang"));
    ac.getFail();
    ac.print();
    int res = ac.search(string("duanxianqiang"));
    cout<<res<<endl;
    return 0;
}
