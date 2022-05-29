#include "utils.h"
// *判断链表是否有环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        //-使用双指针判断是否能相遇
        while(fast!=nullptr&&fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};