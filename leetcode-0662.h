#include "utils.h"
// *计算二叉树的最大宽度（比较每一层），宽度指每一层的最左最右非空节点之间的长度（包括了中间的null）
class Solution {
public:
    //-思路：使用BFS遍历每一层,然后在下一层只插入非空的孩子,就能快速获得头尾的两个节点
    //-但是怎么快速获得头尾节点之间有多少个null呢，如果直接存null，然后来逐层遍历一遍来算距离的话，空间复杂度和时间复杂度都很高，
    //-但是我们假设一个满二叉树的背景，将当前的树嵌入到背景里，则每个节点都有其在完全二叉树下的坐标，利用该坐标可以迅速计算出距离，
    //-所以维护一个数据结构，利用pair来存其原本的节点编号和对应在完全二叉树下的节点编号
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        deque<pair<TreeNode*,long>> dq;
        dq.emplace_back(root,1);
        int maxlength = 0;
        while(!dq.empty()){
            long head = dq.front().second;
            long end = dq.back().second;
//            cout<<"head: "<<head<<" end: "<<end<<endl;
            maxlength = max(maxlength, (int)(end - head + 1));
            int size = (int)dq.size();
            for(int i = 0;i<size;++i){
                pair<TreeNode*,int> temp = dq.front();
                dq.pop_front();
                if(temp.first->left!=nullptr){
                    dq.emplace_back(temp.first->left,temp.second*2);
                }
                if(temp.first->right!=nullptr){
                    dq.emplace_back(temp.first->right,temp.second*2+1);
                }
            }
        }
        return maxlength;
    }
};