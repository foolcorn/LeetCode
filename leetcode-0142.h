#include "utils.h"
// *求链表的入环起点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        //-首先走到相遇的地方
        while(fast != nullptr&&fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                break;
            }
        }
        //-判断是否是因为相遇才打破的循环,还是链表没有环
        if(fast == nullptr || fast->next== nullptr){
            return nullptr;
        }
        //-让其中之一变回头结点,以相同的速度前进,相遇的地方就是环的起始点.
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};