//链表中环相关的问题：一快一慢两个指针,根据指针是否会相遇判断是否存在环
//若有环，可从相遇点开始，再遍历一圈，找到环的大小
//相遇点到环入口距离+K倍环的大小刚好等于起点到环入口距离
//破坏性解法：每遍历一个节点，都将该节点的断开，若存在环，那么环的入口在第二次遍历时，next则为NULL
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (!pHead->next)
            return NULL;
        ListNode* previous = pHead;
        ListNode* front = pHead ->next;
        while (front)
        {
            previous->next = NULL;
            previous = front;
            front = front->next;
        }
        return previous;
    }
};

//version 2
//链接：https://www.nowcoder.com/questionTerminal/253d2c59ec3e4bc68da16833f79a38e4
//来源：牛客网
public class Solution {
 
  
 
    public ListNode EntryNodeOfLoop(ListNode pHead){
 
        ///
 
        if(pHead==null|| pHead.next==null|| pHead.next.next==null)returnnull;
 
        ListNode fast=pHead.next.next;
 
        ListNode slow=pHead.next;
 
        /////先判断有没有环
 
        while(fast!=slow){
 
            if(fast.next!=null&& fast.next.next!=null){
 
                fast=fast.next.next;
 
                slow=slow.next;
 
            }else{
 
                //没有环,返回
 
                returnnull;
 
            }
 
        }
 
        //循环出来的话就是有环，且此时fast==slow.
 
        fast=pHead;
 
        while(fast!=slow){
 
            fast=fast.next;
 
            slow=slow.next;
 
        }
 
        return slow;
 
    }
}

//version 3 
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        set<ListNode*> s;
        while(pHead!=NULL){
            if(s.find(pHead)!=s.end())return pHead;
            s.insert(pHead);
            pHead = pHead->next;
        }
        return NULL;
    }
};

