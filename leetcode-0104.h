#include "utils.h"
// *二叉树最大深度
class Solution {
private:
    int max_depth;
public:
    int maxDepth(TreeNode* root) {
        traverse(root, 1);
        return max_depth;
    }
    void traverse(TreeNode* root, int depth){
        if(root == nullptr){
            return;
        }
        max_depth = max(max_depth, depth);
        traverse(root->left, depth+1);
        traverse(root->right, depth+1);
    }
};