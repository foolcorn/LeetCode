#include "utils.h"
// *合并k个有序链表
struct cmp{
    bool operator()(ListNode*lhs, ListNode*rhs){
        return lhs->val > rhs->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){return nullptr;}
        //-这里不知道为啥lambda用不了
        priority_queue<ListNode*,vector<ListNode*>,cmp> plqueue;
//        priority_queue<ListNode*,vector<ListNode*>,[](ListNode*a,ListNode*b){return a->val>b->val;}> plqueue;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        //-先让每一个链表队头入队,考虑队头就是nullptr的情况
        for(auto ele:lists){
            if(ele){
                plqueue.push(ele);
            }
        }
        //-类似BFS的思路
        while(!plqueue.empty()){
            //-队头出队，让合并链的next指向它
            p->next = plqueue.top();
            plqueue.pop();
            //-后面是否还有节点
            p = p->next;
            if(p->next){
                //-有节点再继续入队
                plqueue.push(p->next);
            }
        }
        return dummy->next;
    }
};