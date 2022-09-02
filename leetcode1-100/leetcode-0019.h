#include "utils.h"
// *删除链表的倒数第N个节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            return nullptr;
        }
        //-构建虚拟头节点
        ListNode* dummy = new ListNode();
        dummy->next = head;
        //-右指针指向head
        ListNode* right = head;
        //-左指针指向dummy,防止删除到头结点
        ListNode* left = dummy;
        //-右指针先走n步
        for(int i = 0;i<n;++i){
            right = right->next;
        }
        //-左右指针同时走
        while(right!=nullptr){
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        return dummy->next;
    }
};