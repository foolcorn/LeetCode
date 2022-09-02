#include "utils.h"
// * 访问不到head，删除特定node
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*next = node->next;
        swap(node->val,next->val);
        node->next = node->next->next;
        delete next;
    }
};