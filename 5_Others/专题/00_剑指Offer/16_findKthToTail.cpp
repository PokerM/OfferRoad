/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p=pListHead;
        ListNode* q=nullptr;
        int i=0;
        while(p!=nullptr){
            p = p->next;
            i++;
            if(q!=nullptr)q=q->next;
            if(i==k)q=pListHead;
        }
        return q;
    }
};