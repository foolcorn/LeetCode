#include "utils.h"
// *将BST转换成累加树，使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。
class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        traceback(root);
        return root;
    }
    //-思路：因为BST比root大的节点都在右边，从右向左遍历，同时用中序遍历来更新节点的值
    void traceback(TreeNode* root){
        if(root == nullptr){
            return;
        }
        traceback(root->right);
        sum+=root ->val;
        root->val = sum;
        traceback(root -> left);
    }
};