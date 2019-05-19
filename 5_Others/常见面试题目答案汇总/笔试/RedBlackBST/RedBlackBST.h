#ifndef REDBLACKBST_H
#define REDBLACKBST_H

const bool RED = false;
const bool BLACK = true;
template <typename T>
struct Node{
    bool         color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    T            val;
    Node(T value):color(BLACK),left(nullptr),right(nullptr),parent(nullptr),val(val){}
};

template <typename T>
class RedBlackBST
{
private:
    Node<T>* root;
    void leftRotate(Node<T>* node);
    void rightRotate(Node<T>* node);
    void flipColor(Node<T>* node);
    Node<T>* put(Node<T>* h, T val);
public:
    RedBlackBST(T value):root(value){};
    ~RedBlackBST(){
        
    }
    void insert(T value);
};

template <typename T>
void RedBlackBST<T>::leftRotate(Node<T>* node){
    Node<T>* p = node->parent;
    p->left = node->left;
    p->left->parent = p;
    node->left = p;
    p->parent = node;
    node->color = p->color;
    p->color = RED;
}

template <typename T>
void RedBlackBST<T>::rightRotate(Node<T>* node){
    Node<T>* p = node->parent;
    node->left = p->right;
    p->right->parent = node;
    p->right = node;
    node->parent = p;
    p->color = node->color;
    node->color = RED;
}

template <typename T>
void RedBlackBST<T>::flipColor(Node<T>* node){
    if(node->parent == nullptr)node->color = BLACK;
    else node->color = RED;
    node->left->color = BLACK;
    node->right->color = BLACK;
}

template <typename T>
void RedBlackBST<T>::insert(T value){
    Node<T>* node = new Node<T>(value);

    Node<T>* p = root;
    Node<T>* pre = nullptr;
    while(p != nullptr){
        pre = p;
        if(p->val < value){
            p = p->right;
        }
        else{
            p = p->left;
        }
    }

    node->parent = pre;
    if(pre == nullptr){
        root = node;
    }
    else if(pre->val > value){
        pre->left = node;
    }
    else{
        pre->right = node;
    }

}

template<typename T>
Node<T>* RedBlackBST<T>::put(Node<T>* h, T val){
    if(h == nullptr)return new Node<T>(val);
    
}
#endif