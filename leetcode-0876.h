#include "utils.h"
// *求链表中间节点
class Solution {
public:
    //-快慢指针
    ListNode* middleNode(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast!=nullptr&&fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};