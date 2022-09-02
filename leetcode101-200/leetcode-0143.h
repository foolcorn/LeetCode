#include "utils.h"
// *重排链表
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodelist;
        ListNode* p = head;
        while(p!=nullptr){
            nodelist.push_back(p);
            p = p->next;
        }
        int left = 0;
        int right = nodelist.size()-1;
        while(left<right){
            nodelist[left++]->next = nodelist[right--];
            // cout<<left<<right<<endl;
            if(left > right){
                nodelist[right+1]->next = nullptr;
                break;
            }
            if(left == right){
                nodelist[right+1]->next = nodelist[left];
                nodelist[left]->next = nullptr;
                break;
            }
            nodelist[right+1]->next = nodelist[left];
        }
    }
};
