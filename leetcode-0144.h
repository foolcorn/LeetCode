#include "utils.h"
// *二叉树前序遍历
class Solution {
    vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        traceback(root);
        return res;
    }

    void traceback(TreeNode* root){
        if(root == nullptr){
            return;
        }
        res.push_back(root->val);
        traceback(root->left);
        traceback(root->right);
    }
};
