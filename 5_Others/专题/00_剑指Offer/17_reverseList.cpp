class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead)return NULL;
        ListNode* res = NULL;
        ListNode* cur = pHead;
        ListNode* tmp = cur;
        while(cur != NULL){
            tmp = cur;          //保存当前节点
            cur = cur ->next;   //指向下一节点
            tmp->next = res;    //将当前节点与链表连接起来
            res = tmp;
        }
        return res;
    }
};