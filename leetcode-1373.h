#include "utils.h"
// *二叉搜索树最大键值和：
// *从一颗二叉树找一颗有最大键值和的BST子结构
lass Solution {
        private:
        int maxsum;
        public:
        //-在一棵树里找最高的二叉搜索树，后序遍历
        int maxSumBST(TreeNode* root) {
            maxsum = 0;
            traceback(root);
            return maxsum;
        }
        //-vector{是否是搜索树标志位，最大值，最小值，键值和}
        vector<int> traceback(TreeNode* root) {
            if(root == nullptr){
                //-这里隐含了一个判断,如果root一开始就为0,则sum=0
                return {1,INT_MIN,INT_MAX,0};
            }
            vector<int> left = traceback(root->left);
            vector<int> right = traceback(root->right);
            //-如果左右子树不是BST,直接返回首元素为0的vector即可
            if(left[0]==0||right[0]==0){
                return {0,0,0,0};
            }
            //-如果加上root后的整棵树不是BST,直接返回首元素为0的vector即可
            if(root->val<=left[1]||root->val>=right[2]){
                return {0,0,0,0};
            }
            //-没问题的话更新vector
            int sign = 1;
            int maxele = max(right[1],root->val);//-这里取max的原因还是为了baseclass的情况(左右节点为null时,root作为最大值)
            int minele = min(left[2],root->val);//-和上面同理
            int sum = left[3]+right[3]+root->val;
            maxsum = max(sum,maxsum);
            return{sign,maxele,minele,sum};
        }
};