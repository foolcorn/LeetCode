#include "utils.h"
// *给定n，用1-n的n个节点构造所有可能的二叉树并返回
class Solution {
public:

    vector<TreeNode*> generateTrees(int n) {
        vector<int> nodes;
        for (int i = 1; i <= n;++i){
            nodes.push_back(i);
        }
        return traceback(nodes, 0, n);
    }
    //-想象着tracback的返回值，不是节点的数组，而是一颗颗树的数组
    //-这些树在递归的过程中，连接了不同的子树，代表着一种BST的可能性
    vector<TreeNode*> traceback(const vector<int> &nodes, int left, int right) {
        if(left >= right){
            return {nullptr};
        }
        vector<TreeNode*> res;
        for(int i = left;i < right; ++i){
            //-思路：使用分治思想，在当前范围内，选定一个节点作为root，在子范围内构造二叉搜索树
            vector<TreeNode*> leftres = traceback(nodes,left,i);
            vector<TreeNode*> rightres = traceback(nodes,i+1,right);
            for(auto lefttree:leftres){
                for(auto righttree:rightres){
                    //-对于左右子树的每一种可能,都有一个新节点来连接每一种左右子树,并插入到答案
                    TreeNode* temp = new TreeNode(nodes[i]);
                    temp->left =lefttree;
                    temp->right = righttree;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};