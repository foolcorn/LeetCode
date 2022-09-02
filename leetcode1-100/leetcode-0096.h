#include "utils.h"
// *给定n，假设有节点1-n，能组成有几种不同二叉搜索树
class Solution {
    vector<vector<int>> memo;
    //-思路：使用分治思想，在当前范围内，选定一个节点作为root，在子范围内构造二叉搜索树
public:
    int numTrees(int n) {
        if(n==0){return 0;}
        memo = vector<vector<int>>(n+1,vector<int>(n+1,-1));
        vector<int> nodes;
        for (int i = 1; i <= n; ++i) {
            nodes.push_back(i);
        }
        //-我这里范围用了左闭右开区间
        return countTrees(nodes,0,n);
    }
    int countTrees(const vector<int> &nodes, int left, int right){
        //-当范围内只有一个元素就返回1种可能
        if(left>=right-1){
            return 1;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        int count = 0;
        //-在当前范围内，选定一个节点作为root
        for(int i = left;i<right;++i){
            int leftnum = countTrees(nodes,left,i);
            int rightnum = countTrees(nodes,i+1,right);
            //-左右可能性有m*n种组合
            count += leftnum*rightnum;
        }
        memo[left][right] = count;
        return memo[left][right];
    }
};