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
        //-假设环起点距离相遇点为m，则slow走了k步到到相遇点，则slow从头开始走k-m步可以到起点
        //-而fast从相遇点走k-m步，也能到环起点。
        //-抽象的话，第一次相遇的时候，k代表了n圈都有可能，但是不管走几圈，-m后都能到环起点。
        //-让其中之一变回头结点,以相同的速度前进,相遇的地方就是环的起始点.
        fast = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};