#include "utils.h"
// *在BST中搜索值
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }
        if(val>root->val){
            return searchBST(root->right,val);
        }else if (val<root -> val){
            return searchBST(root->left,val);
        }else{
            return root;
        }
    }
};