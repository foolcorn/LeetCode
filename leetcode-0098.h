#include "utils.h"
// *验证BST是否合法
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return traceback(root, nullptr, nullptr);
    }
    bool traceback(TreeNode* root,TreeNode* mintree, TreeNode* maxtree){
        if(root==nullptr){
            return true;
        }
        if(mintree!=nullptr&&root->val <=mintree->val){
            return false;
        }
        if(maxtree!=nullptr&&root->val >=maxtree->val){
            return false;
        }
        return traceback(root->left,mintree, root)&&traceback(root->right,root,maxtree);
    }
};