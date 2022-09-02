#include "utils.h"
// *BST的最近公共祖先
class Solution {
    //-思路：从上往下，如果root比max大，就在左边找，如果root比min小，就在右子树找
    //-如果等于root任何一个，就返回root，或者root在minmax之间，也返回root
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int maxval = max(p->val,q->val);
        int minval = min(p->val,q->val);
        return traceback(root, minval, maxval);
    }
    TreeNode* traceback(TreeNode* root, int minval, int maxval){
        if(root->val>maxval){
            return traceback(root->left, minval, maxval);
        }else if(root->val<minval){
            return traceback(root->right, minval, maxval);
        }else {
            return root;
        }
    }
};
