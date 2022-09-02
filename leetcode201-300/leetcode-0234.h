#include "utils.h"
// *判断回文链表
class Solution {
public:
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        return traceback(head);
    }
    bool traceback(ListNode* node){
        if(node==nullptr){
            return true;
        }
        if(!traceback(node->next)){
            return false;
        }else{
            if(left->val==node->val){
                left = left->next;
                return true;
            }else{
                return false;
            }
        };
    }
};