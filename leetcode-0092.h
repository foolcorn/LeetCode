#include "utils.h"
// * 反转链表2，反转指定区间的链表

class Solution {
    ListNode* new_tail = nullptr;
public:
    //-先写一个反转前N个节点的函数
    ListNode* reverseN(ListNode* node, int n){
        if(n==1){
            new_tail = node->next;
            return node;
        }
        ListNode* new_head = reverseN(node->next,n-1);
        ListNode* next_node = node -> next;
        next_node->next = node;
        node -> next = new_tail;
        return new_head;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //-判断只有一个节点的情况
        if(head->next == nullptr){

            return head;
        }
        //-单独判断left==1，也就是从头节点开始反转的情况
        int n = right - left+1;
        if(left == 1){
            return reverseN(head,n);
        }
        //-如果是从中间开始反转，就推移到对应位置开始反转n个节点
        ListNode* p = head;
        for (int i = 1; i < left-1; ++i) {
            p = p -> next;
        }
        p->next = reverseN(p->next,n);
        return head;
    }
};