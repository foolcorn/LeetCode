#include "utils.h"
// * 反转链表（递归版）
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return traceback(head);
    }
    ListNode* traceback(ListNode* node){
        //-node==nullptr是为了排除root为null的情况，其他情况返回的new_head都是真实节点
        if(node == nullptr||node->next == nullptr){
            return node;
        }
        //-获得下一个元素
        ListNode* next_node = node->next;
        //-先递归入栈
        ListNode* new_head = traceback(next_node);
        //-对于当前元素,后一个指向自己,自己的下一个指向nullptr
        next_node->next = node;
        node->next = nullptr;
        return new_head;
    }
};