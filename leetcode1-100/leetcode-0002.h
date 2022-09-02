#include "utils.h"
// *两数相加，两个数每个数位是用链表形式存储，返回相加后的数（链表形式）
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int next = 0;
        ListNode* dummy = new ListNode();
        ListNode* last = dummy;
        while(l1!=nullptr||l2!=nullptr){
            int ele1 = l1 ? l1 -> val : 0;
            int ele2 = l2 ? l2 -> val : 0;
            int val = ele1 + ele2 + next;
            next = 0;
            if(val>=10){
                val %= 10;
                next = 1;
            }
            ListNode* temp = new ListNode(val);
            last->next = temp;
            last = temp;
            l1 = l1? l1 -> next : l1;
            l2 = l2? l2 -> next : l2;
        }
        if(next == 1){
            last->next = new ListNode(next);
        }
        return dummy->next;
    }
};