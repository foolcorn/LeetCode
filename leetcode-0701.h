#include "utils.h"
// *在BST中插入==val的节点
class Solution {
public:
    //-说实话，这个思路挺厉害的，需要记一下
    //-我们的目的是要一直搜索到插入位置,也就是某个叶子节点的左枝或者右枝:都是nullptr
    //-细节在于使用TreeNode作为返回值，让对应位置的父亲能接上孩子的节点
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //-如果找到了位置,就返回这个新节点
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(val > root->val){
            root->right = insertIntoBST(root->right, val);
        }else if(val < root->val){
            root->left = insertIntoBST(root->left, val);
        }
        //-只要当前节点不是nullptr,就将自己本身返回
        return root;
    }
};