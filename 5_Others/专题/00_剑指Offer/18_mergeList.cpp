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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* res=NULL;
        ListNode* p=NULL;
        if(pHead1!=NULL&&pHead2!=NULL){
            if(pHead1->val>pHead2->val){
                res = pHead2;
                pHead2 = pHead2->next;
            }
            else{
                res = pHead1;
                pHead1 = pHead1->next;
            }
        }
        else{
            if(pHead1==NULL)return pHead2;
            return pHead1;
        }
        p = res;
        while(pHead1!=NULL&&pHead2!=NULL){
            if(pHead1->val>pHead2->val){
                res->next = pHead2;
                pHead2 = pHead2->next;
            }
            else{
                res->next = pHead1;
                pHead1 = pHead1->next;
            }
            res = res->next;
        }
        if(pHead1!=NULL){
            res->next = pHead1;
            pHead1 = NULL;
        }
        else{
            res->next = pHead2;
            pHead2 = NULL;
        }
        return p;
    }
};