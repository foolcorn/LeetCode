#include "utils.h"
// *二叉树最大路径和，这题我做的太复杂了，重做吧
class Solution {
private:
    int res = INT_MIN;//-这里设成int_min而不是0是防止root就为负数
public:
    int maxPathSum(TreeNode* root) {
        traceback(root);
        return res;
    }
    //-返回当前节点的最大深度
    int traceback(TreeNode* root){
        //-如果是根节点没深度
        if(root == nullptr){
            return 0;
        }
        //-如果深度是负数，那么就不连接该子树，所以将depth长度归零，如果深度是正数，就加上。
        int maxleftlength = max(0,traceback(root->left));
        int maxrightlength = max(0,traceback(root->right));
        //-连接当前节点获得最长路径
        int newlength = root->val+maxleftlength+maxrightlength;
        //-更新最长路径
        res = max(res,newlength);
        //-返回新的最大深度
        return max(maxleftlength,maxrightlength)+root->val;
    }
};
