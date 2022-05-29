#include "utils.h"
// *二叉树最小深度
class Solution {
//    -使用BFS解法
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr){return 0;}
        //-建立一个队列
        deque<TreeNode*> queue;
        queue.push_back(root);
        int depth = 1;
        while (!queue.empty()){
            int size = (int)queue.size();
            for(int i = 0;i<size;++i){
                TreeNode* temp = queue.front();
                queue.pop_front();
                if(temp->left == nullptr&&temp->right == nullptr){
                    return depth;
                }
                if(temp->left!=nullptr){queue.push_back(temp->left);}
                if(temp->right!=nullptr){queue.push_back(temp->right);}
            }
            ++depth;
        }
        return depth;
    }
};