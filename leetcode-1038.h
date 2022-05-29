#include "utils.h"
// *将BST转换为更大和数，将每个节点的值替换成树中大于或者等于该节点值的所有节点值之和
class Solution {
private:
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        traceback(root);
        return root;
    }
    //-思路：因为BST比root大的节点都在右边，从右向左遍历，同时用中序遍历来更新节点的值
    void traceback(TreeNode* root){
        if(root == nullptr){
            return;
        }
        traceback(root->right);
        root->val+=sum;
        sum = root->val;
        traceback(root->left);
    }
};