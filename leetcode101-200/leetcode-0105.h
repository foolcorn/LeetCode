#include "utils.h"
// *前序遍历和中序遍历构造二叉树
class Solution {
private:
    unordered_map<int,int> inmap;
    vector<int> preorder;
    vector<int> inorder;

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //-用map的这个思路挺不错
        for(int i = 0;i<inorder.size();++i){
            inmap[inorder[i]] = i;
        }
        this->preorder = preorder;
        this->inorder = inorder;
        return traverse(0,preorder.size(),0,inorder.size());
    }
    TreeNode* traverse(int pre_satrt, int pre_end, int in_start, int in_end){
        if(pre_satrt>=pre_end||in_start>=in_end){
            return nullptr;
        }
        //-找到根元素
        int rootvalue = preorder[pre_satrt];
        //-计算根元素左边有多少元素
        auto index = inmap[rootvalue];
        int left_length = index-in_start;
        TreeNode * root = new TreeNode(rootvalue);
        //-递归两个数组
        root->left = traverse(pre_satrt+1,pre_satrt+1+left_length,in_start,index);
        root->right = traverse(pre_satrt+1+left_length,pre_end,index+1,in_end);
        return root;
    }
};

