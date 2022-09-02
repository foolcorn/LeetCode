#include "utils.h"
// *二叉树的最近公共祖先
class Solution {
    //-思路：通过后序位置判断递归返回值，如果找到子节点就返回子节点，否则返回nullptr
    //-如果左右都找到了，就返回root就是了
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traceback(root, p, q);
    }

    TreeNode* traceback(TreeNode* root, TreeNode*p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* leftt = traceback(root->left,p,q);
        TreeNode* rightt = traceback(root->right,p,q);
        if(leftt != nullptr && rightt != nullptr){
            return root;
        }
        return leftt ? leftt:rightt;
    }
};