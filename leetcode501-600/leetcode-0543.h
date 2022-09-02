#include "utils.h"
// *二叉树的直径：
// *一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxsum = 0;
        traverse(root,maxsum);
        return maxsum;
    }
    int traverse(TreeNode* root, int &max_length){
        if(root == nullptr){
            return 0;
        }
        int depthleft = traverse(root->left,max_length);
        int depthright = traverse(root->right,max_length);
        int sum = depthleft+depthright;
        max_length = max(sum,max_length);
        int length = max(depthleft, depthright)+1;
        return length;
    }
};