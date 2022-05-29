#include "utils.h"
// *打家劫舍3：房屋是二叉树，相邻节点不能偷
class Solution {
private:
    unordered_map<TreeNode*,vector<int>>memo;
public:
    int rob(TreeNode* root) {
        return rob(root,1);
    }
    //-sign标志指示能不能偷
    int rob(TreeNode* root, int sign){
        if(memo.count(root)==0){
            memo[root] = vector<int>(2,-1);
        }
        if(root == nullptr){
            //-叶子结点偷不了
            return 0;
        }
        if(memo[root][sign]!=-1){
            return memo[root][sign];
        }
        if(sign == 0){
            //-当前肯定不能偷，但是左右子树设置为能偷
            memo[root][sign] = rob(root->left,1)+rob(root -> right,1);
            return memo[root][sign];
        }
        //-如果不偷当前的，计算从左右子树开始偷的钱
        int res1 = rob(root->left,1)+rob(root -> right,1);
        //-如果偷了当前的，左右子树设置为不能偷
        int res2 = root->val+rob(root->left,0)+rob(root->right,0);
        //-返回最大答案
        memo[root][sign] = max(res1, res2);
        return memo[root][sign];
    }
};