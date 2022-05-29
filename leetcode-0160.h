#include "utils.h"
// *判断两个链表相交的起始点，或者不相交返回null
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * p1 = headA;
        ListNode * p2 = headB;
        //-死循环
        while(true){
            //-两个都走到头了
            if(p1 == nullptr&&p2 == nullptr){
                break;
            }
            //-接到另一边
            if(p1 == nullptr){
                p1 = headB;
            }
            //-接到另一边
            if(p2 == nullptr){
                p2 = headA;
            }
            //-第一个相交节点
            if(p1 == p2){
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};