#include "utils.h"
// *返回二叉树每一行的最大值
class Solution {
    unordered_map<int,int> gmap;
public:
    vector<int> largestValues(TreeNode* root) {
        traceback(root,0);
        int i = 0;
        vector<int> temp;
        while(gmap.count(i)>0){
            temp.push_back(gmap[i]);
            ++i;
        }
        return temp;
    }
    void traceback(TreeNode* root, int depth){
        if(root == nullptr){
            return;
        }
        int val = root->val;
        if(gmap.count(depth)==0){
            gmap[depth] = val;
        }else{
            if(val>gmap[depth]){
                gmap[depth] = val;
            }
        }
        traceback(root->left,depth+1);
        traceback(root->right,depth+1);
    }
};