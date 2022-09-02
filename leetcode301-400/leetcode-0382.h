#include "utils.h"
// *在不知道链表长度的情况下，等概率地返回链表其中一个节点的值
class Solution {
private:
    //-思路：水塘抽样算法,遍历到节点i(从1开始)的时候,都会有1/i的概率选择该节点,而有1-i/1的概率保持原有选择
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }
    int getRandom() {
        ListNode* p = head;
        int res = 0;
        int count = 0;
        while(p!=nullptr){
            ++count;//-因为count从0开始计数，所以先++，等价于从1开始的后置++count
            if(0 == rand()%count){//-从[0,count)中随机一个数==0的概率就是1/count
                res = p->val;//-如果res被覆盖，意味着再次因为1/i的概率选择了新的节点，而没有保持原来的选择
            }
            p = p->next;
        }
        return res;
    }
};