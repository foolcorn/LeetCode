#include "utils.h"
// *k个一组反转链表
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i = 0; i < k-1; i++){
            if(temp == nullptr){
                return head;
            }
            temp = temp->next;
        }
        ListNode* new_head = reverseK(head,k-1);
        head->next = reverseKGroup(temp->next,k);
        return new_head;
    }
    ListNode* reverseK(ListNode* node, int k){
        if(k == 0){
            return node;
        }
        ListNode* next_node = node->next;
        ListNode* new_head = reverseK(next_node,k-1);
        next_node->next = node;
        node->next = nullptr;
        return new_head;
    }
};
// -旧方法，把不满k个不反转返回旧头和满k个反转并返回新头的判定结合在一个reverseK里了，
// -其实把这个判定写在reverseKgroup里会更好看，但是效率会差点。
class Solution_old {
    ListNode* newtail;
    bool sign = true;
public:
    //-理清思路，怎么写递归，k个一组，后序递归，从后往前，返回新的head，然后让当前组的尾巴（反转前的头部）连上new head
    //-大循环就判定一下满不满k个，满k个就反转k个，返回新的头部（原来的尾巴），旧的头部(新的尾巴)接下一次大循环的返回值
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