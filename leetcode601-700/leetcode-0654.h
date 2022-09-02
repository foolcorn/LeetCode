#include "utils.h"
// *最大二叉树，从数组递归构建二叉树，
// *root为nums最大值，
// *nums最大值 左边的子数组继续构建root左子树，右边子数组构建右子树
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traceback(nums,0,nums.size());
    }
    TreeNode* traceback(vector<int>& nums, int start , int end){
        if(start == end){
            return nullptr;
        }
        int maxele = -1;
        int index = start;
        for(int i = start;i<end;++i){
            if(nums[i]> maxele){
                maxele = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(maxele);
        root->left = traceback(nums,start,index);
        root->right = traceback(nums,index+1,end);
        return root;
    }
};