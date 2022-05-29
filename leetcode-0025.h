#include "utils.h"
// *k个一组反转链表
// -旧方法，把不满k个不反转返回旧头和满k个反转并返回新头的判定结合在一个reverseK里了，
// -其实把这个判定写在reverseKgroup里会更好看，但是效率会差点。
class Solution {
    ListNode* newtail;
    bool sign = true;
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newhead = reverseK(head, k);
        if(sign){
            head->next = reverseKGroup(head->next, k);
            return newhead;
        }else{
            return head;
        }
    }
    ListNode* reverseK(ListNode* node,int k){
        //-k还没降到0就无了
        if(node == nullptr){
            sign = false;
            return nullptr;
        }
        if(k==1){
            newtail = node->next;
            return node;
        }
        ListNode* newhead = reverseK(node->next,k-1);
        if(!sign){
            return nullptr;
        }
        node->next->next = node;
        node->next = newtail;
        return newhead;
    }
};