#include "utils.h"
// *将两颗BST合并成一个有序数组
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1;
        vector<int> list2;
        vector<int> res;
        traceback(root1,list1);
        traceback(root2,list2);
        int p1 = 0;
        int p2 = 0;
        int size1 = (int)list1.size();
        int size2 = (int)list2.size();
        while(p1!=size1 && p2!=size2){
            if(list1[p1]<=list2[p2]){
                res.push_back(list1[p1]);
                ++p1;
            }else {
                res.push_back(list2[p2]);
                ++p2;
            }
        }
        if(p1 == size1){
            for(;p2<size2;++p2){res.push_back(list2[p2]);}
        }else{
            for(;p1<size1;++p1){res.push_back(list1[p1]);}
        }
        return res;
    }
    void traceback(TreeNode* root, vector<int> &list){
        if(root == nullptr){
            return;
        }
        traceback(root->left,list);
        list.push_back(root->val);
        traceback(root->right,list);
    }
};