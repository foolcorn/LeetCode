#include "utils.h"
// * 把二叉树展开为单链表
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        flatten(root->left);
        flatten(root->right);
        //-使用后序遍历，先把左右两边的子树都打平成链表
        //-先保存右子树的副本，将左子树接在右边
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode* final = root;
        //-遍历到左子树最后一个节点
        while(final->right!= nullptr){
            final = final->right;
        }
        //-把原来的右子树接到左子树后面
        final->right = right;
    }
};