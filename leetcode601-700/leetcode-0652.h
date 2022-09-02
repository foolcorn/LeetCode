#include "utils.h"
// *二叉树里寻找所有重复的子树，子结构，返回数组只包含重复的任意一颗树的根节点
class Solution {
    //-创建序列unordered_map
    unordered_map<string,int> string_map;
    vector<TreeNode*> res;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }
    //-先序遍历序列化
    string traverse(TreeNode* root){
        if(root == nullptr){
            return "#";
        }
        string left = traverse(root->left);
        string right = traverse(root->right);
        //-后序遍历,把子树进行序列化,存到map里
        string series = to_string(root->val)+"-"+left+"-"+right;
        //-如果无重复,插入
        if(string_map.count(series)==0){
            string_map[series] = 1;
        }else{
            //-如果正好是第一次重复，插入到res里，不是第一次重复就继续更新map计数，并忽略res
            if(string_map[series] == 1){
                res.push_back(root);
            }
            ++string_map[series];
        }
        return series;
    }
};