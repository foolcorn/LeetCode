#include "utils.h"
// *删除有序链表中的重复元素
class Solution {
public:
    //-思路和数组一样，双指针，left指向上一个的不重复元素，right在前面不断和left匹配。
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr){
            return head;
        }
        ListNode* left = head;
        if(head->next == nullptr){
            return head;
        }
        ListNode* right = head->next;
        while(right!=nullptr){
            if(right->val != left->val){
                left->next = right;
                left = right;
                right = right->next;
            }else{
                //-考虑到从某刻开始right一直都是重复元素，就在重复的开始讲left->next设为null
                left->next = nullptr;
                right = right -> next;
            }
        }
        return head;
    }
};