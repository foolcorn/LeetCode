#include "utils.h"
// *锯齿遍历二叉树
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        bool left_right = true;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            int size = queue.size();
            deque<int> temp;
            for (int i = 0; i < size;++i){
                TreeNode* node = queue.front();
                queue.pop_front();
                if(left_right){
                    temp.push_back(node->val);
                }else{
                    temp.push_front(node->val);
                }
                if(node->left!=nullptr){
                    queue.push_back(node->left);
                }
                if(node->right!=nullptr){
                    queue.push_back(node->right);
                }
            }
            vector<int> temp2(temp.begin(),temp.end());
            res.push_back(temp2);
            left_right = !left_right;
        }
        return res;
    }
};

