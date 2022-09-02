#include "utils.h"
// *中序遍历和后序遍历构造二叉树
class Solution {
private:
    vector<int> ginorder;
    vector<int> gpostorder;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        ginorder = inorder;
        gpostorder = postorder;
        return traceback(0,inorder.size(),0,postorder.size());
    }
    TreeNode* traceback(int instart, int inend, int poststart, int postend){
        if(instart == inend||poststart == postend){
            return nullptr;
        }
        //-找到root元素
        int rootvalue = gpostorder[postend-1];
        //-找到索引，应该用个map
        int rootindex = instart;
        for(int i = instart;i<inend;++i){
            if(ginorder[i]==rootvalue){
                rootindex = i;
            }
        }
        int leftlength = rootindex-instart;
        TreeNode* root = new TreeNode(rootvalue);
        root->left = traceback(instart,rootindex, poststart,poststart+leftlength);
        root->right = traceback(rootindex+1,inend, poststart+leftlength,postend-1);
        return root;
    }
};
