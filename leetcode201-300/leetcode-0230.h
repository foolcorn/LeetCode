#include "utils.h"
// *BST第k小的元素
class Solution {
    int count = 0;
    int res;
public:
    //-思路，中序遍历
    int kthSmallest(TreeNode* root, int k) {
        traceback(root,k);
        return res;
    }

    void traceback(TreeNode * root,const int&target){
        if(root == nullptr){
            return;
        }
        traceback(root->left,target);
        ++count;
        if(count == target){
            res = root -> val;
            return;
        }
        traceback(root->right,target);
    }
};