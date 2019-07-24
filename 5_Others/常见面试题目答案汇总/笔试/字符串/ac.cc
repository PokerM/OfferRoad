#include <iostream>

const int kind = 26;
struct Node{
    Node* fail;
    Node* next[kind];
    int count;
    Node(){
        fail = nullptr;
        count = 0;
        memset(next, nullptr, sizeof(next));
    }
}*q[500001];
char keyword[51];
char str[100001];
int head, tail;

void insert(char* str, Node* root){
    Node* p = root;
    int i=0, index;
    while(str[i]!='\0'){
        index = str[i] - 'a';
        if(p->next[index]==nullptr)p->next[index] = new node;
        p = p->next[index];
        i++;
    }
    p->count++;
}
void build_fail_node(Node* root){
    int i = 0;
    root->fail = nullptr;
    q[head++] = root;
    while(head!=tail){
        Node* temp = q[tail++];
        Node* p = nullptr;
        for(int i=0;i<26;i++){
            if(temp->next[i]!=nullptr){
                if(temp==root)temp->next[i]->fail = root;
                else{
                    p = temp->fail;
                    while(p != nullptr){
                        if(p->next[i] != nullptr){
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == nullptr)temp->next[i]->fail = root;
                }
            }
            q[head++] = temp->next[i];
        }
    }
}

int query(Node* root){
    int i=0, cnt = 0, index, len = strlen(str);
    Node* p = root;
    while(str[i]){
        index = str[i] - [a];
        while(p->next[index]==nullptr&&p!=root)p = p->fail;
        p = p->next[index];
        p = (p==nullptr)?root:p;
        Node* temp = p;
        while(temp!=root && temp->count!=-1){
            cnt += temp->count;
            temp->count = -1;
            temp = temp->fail;
        }
        i++;
    }
    return cnt;
}