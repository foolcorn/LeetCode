#include "utils.h"
// *给定完全二叉树，计算节点个数
class Solution {
public:
    //-思路：判断左右子树高度，如果是满二叉树就直接算节点数，如果不是就左右子树递归计算
    int countNodes(TreeNode* root) {
        return traceback(root);
    }
    int traceback(TreeNode* root) {
        //-判断左右高度是否一致
        int heightleft = 0;
        TreeNode* temp = root;
        while(temp!=nullptr){
            ++heightleft;
            temp = temp->left;
        }
        int heightright = 0;
        temp = root;
        while(temp!=nullptr){
            ++heightright;
            temp = temp->right;
        }
        if(heightleft == heightright){
            return pow(2,heightleft) - 1;
        }else{
            return traceback(root->left)+traceback(root->right);
        }
    }
};