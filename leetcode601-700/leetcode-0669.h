#include "utils.h"
// *修剪BST，给定边界，把边界之外的元素删除
class Solution {
    int low;
    int high;
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        this->low = low;
        this->high = high;
        return traceback(root);
    }

    TreeNode* traceback(TreeNode* root){
        if(root == nullptr){
            return nullptr;
        }
        //-如果root小于下界，说明root和左边树也全部要删除，所以返回右子树的递归
        if(root->val<low){
            return traceback(root->right);
            //-同理，如果root大于上界，说明root和右子树也全部要删除，所以返回左子树的递归
        }else if(root->val>high){
            return traceback(root->left);
        }else{//-root没有问题，子树再分别递归判断即可
            root->left = traceback(root->left);
            root->right = traceback(root->right);
            //-返回删除后的根
            return root;
        }
    }
};