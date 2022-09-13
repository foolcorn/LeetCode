#include "utils.h"
// *锯齿遍历二叉树
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr){
            return res;
        }
        //-遍历方向是否是从左到右？
        bool left_right = true;
        //-需要pop_front所以用deque
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            int size = queue.size();
            //-每一层的遍历结果，需要push_front所以用deque
            deque<int> temp;
            for (int i = 0; i < size;++i){
                TreeNode* node = queue.front();
                queue.pop_front();
                //-如果是从左到右，则从尾部插入结果
                if(left_right){
                    temp.push_back(node->val);
                }else{//-反之则从头部插入，变成逆序
                    temp.push_front(node->val);
                }
                //-层序遍历则保持不变，依然是从左到右插入到deque里
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

