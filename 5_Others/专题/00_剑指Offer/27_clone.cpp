/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //第一步：复制新链表节点，放到原节点后面A`=A->next;
        //第二步：将为新链表节点链接随机指针A`.random=A.random.next
        //第三部：拆分链表
        if(pHead == NULL)return NULL;
        RandomListNode* res = NULL;
        RandomListNode* ptr = pHead;
        
        //第一步：复制新链表节点，放到原节点后面A`=A->next;
        while(ptr != NULL){
            RandomListNode* t = new RandomListNode(ptr->label);
            t->next = ptr->next;
            ptr->next = t;
            ptr = t->next;
        }
        
        //第二步：将为新链表节点链接随机指针A`.random=A.random.next
        ptr = pHead;
        while(ptr != NULL){
            if(ptr->random != NULL)
                ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }
        //第三部：拆分链表
        ptr = pHead;
        res = pHead->next;
        RandomListNode* q = res; 
        while(ptr != NULL){
            ptr->next = q->next;
            if(ptr->next)
                q->next = ptr->next->next;
            else
                q->next = NULL;
            q = q->next;
            ptr = ptr->next;
        }
        return res;
    }
};