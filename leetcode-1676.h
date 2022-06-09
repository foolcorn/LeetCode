#include "utils.h"
// *二叉树给定多个节点求公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        unordered_set<TreeNode*> nsets;
        for(auto& node:nodes) {
            nsets.insert(node);
        }
        return traceback(root, nsets);
    }
    TreeNode* traceback(TreeNode* root,unordered_set<TreeNode*> &nodes) {
        if(root == nullptr){
            return nullptr;
        }
        if(nodes.count(root) > 0){
            return root;
        }
        TreeNode* leftt = traceback(root->left,nodes);
        TreeNode* rightt = traceback(root->right,nodes);
        if(leftt != nullptr && rightt != nullptr){
            return root;
        }
        return leftt ? leftt:rightt;
    }
};