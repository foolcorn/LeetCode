#include "utils.h"
// *删除链表重复项
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy = new ListNode;
        dummy->next = nullptr;
        ListNode*p1 = dummy;
        ListNode*p2 = head;
        while(p2!=nullptr) {
            if(p2->next!=nullptr&&p2->next->val != p2->val){
                p1->next = p2;
                p1 = p1->next;
                p2 = p2->next;
                p1->next = nullptr;
            }else if(p2->next == nullptr){
                p1->next = p2;
                p2 = p2->next;
            }else{
                while(p2->next != nullptr&&p2->next->val == p2->val){
                    p2 = p2->next;
                }
                p2 = p2->next;
            }
        }
        return dummy->next;
    }
};