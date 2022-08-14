#include "utils.h"
// *排序链表
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return traceback(head,nullptr);
    }

    ListNode* traceback(ListNode* head, ListNode* tail){
        //-如果一开始就没有元素
        if(head == nullptr){
            return head;
        }
        //-只有一个元素直接返回
        if(head->next == tail){
            head->next = nullptr;
            return head;
        }
        //-有多个元素，先找到中点
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(p2!=tail){
            p1 = p1->next;
            p2 = p2->next;
            if(p2!=tail){
                p2 = p2->next;
            }
        }
        ListNode * head1 = traceback(head,p1);
        ListNode * head2 = traceback(p1,tail);
        return merge(head1,head2);
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        //-如果两个链表都不为空
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while(head1!=nullptr||head2!=nullptr){
            if(head1 == nullptr){
                p->next = head2;
                head2 = head2->next;
                p = p->next;
            }else if(head2 == nullptr){
                p->next = head1;
                head1 = head1->next;
                p = p->next;
            }else if(head1->val>head2->val){
                p->next = head2;
                head2 = head2->next;
                p = p->next;
            }else {
                p->next = head1;
                head1 = head1->next;
                p = p->next;
            }
        }
        return dummy->next;
    }
};