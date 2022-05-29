#include "utils.h"
// *删除BST的节点
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return traceback(root,key);
    }
    TreeNode* traceback(TreeNode* root, int key){
        if(root == nullptr){
            return nullptr;
        }
        if(root->val!=key){
            root->left = traceback(root->left,key);
            root->right = traceback(root->right,key);
            return root;
        }
        //-如果是叶子结点,直接删除自己
        if(root->left == nullptr&&root -> right == nullptr){
            return nullptr;
        }
        //-如果右节点空，左节点非空，接上左节点
        if(root->right == nullptr){
            return root->left     ;
        }
        //-如果左节点空，右节点非空，接上右节点
        if(root->left == nullptr){
            return root->right;
        }
        //-如果左右节点非空，让右子树的最小值成为root
        TreeNode* prev = root;
        TreeNode* temp = root->right;
        //-如果第一个右枝条有左枝条，就遍历到最左，否则temp就取第一个右枝条为最小值
        while(temp->left != nullptr){
            prev = temp;
            temp = temp->left;
        }
        //-把原root的左枝条接在temp上
        temp->left = root->left;
        //-如果temp有右枝条，接在temp的父亲上
        prev->left = temp->right;
        //-如果右枝条的首元素不是temp,就让旧root的右枝条接在temp的右枝条上（如果是首元素则根本不用接）
        if(temp!=root->right){
            temp->right = root->right;
        }
        //-temp作为新的root返回
        return temp;
    }
};