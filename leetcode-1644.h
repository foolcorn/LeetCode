#include "utils.h"
// * 二叉树的最近公共祖先，p或者q之一如果不在二叉树中，就返回null
class Solution {
private:
    bool foundp = false;
    bool foundq = false;
public:
    //-思路，定义两个全局变量来指代p是否找到了
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = traceback(root, p, q);
        if(foundp&&foundq){
            return res;
        }
        return nullptr;
    }

    TreeNode* traceback(TreeNode* root, TreeNode*p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        TreeNode* leftt = traceback(root->left, p, q);
        TreeNode* rightt = traceback(root->right,p,q);
        //-为什么要放这个位置，想象如果p和q其中之一就是公共祖先，如果是先序位置，找到p就直接返回root，而无法遍历到其子树q，也没法更新foundq
        if(root == p){
            foundp = true;
            return root;
        }
        if(root == q){
            foundq = true;
            return root;
        }
        if(leftt != nullptr&& rightt != nullptr){
            return root;
        }
        return leftt? leftt:rightt;
    }
};