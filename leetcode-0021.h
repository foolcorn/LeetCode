
#include "utils.h"
// *合并两个有序链表
class Solution {
public:
    //-学完了归并排序以后再来写这个,就很容易了
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(p1!=nullptr||p2!=nullptr){
            if(p1 == nullptr){
                temp->next = p2;
                temp = temp->next;
                p2 = p2->next;
            }else if(p2 == nullptr){
                temp->next = p1;
                temp = temp->next;
                p1 = p1->next;
            }else if(p1->val>p2->val){
                temp->next = p2;
                temp = temp->next;
                p2 = p2->next;
            }else{
                temp->next = p1;
                temp = temp->next;
                p1 = p1->next;
            }
        }
        return dummy->next;
    }
};