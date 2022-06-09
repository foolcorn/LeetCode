#include "utils.h"
// *一颗z字形无限完全二叉树，给定节点label，求从根节点到该label的路径
class Solution {
public:
    //-思路：先从lable回溯到root，并将答案reverse即可。
    //-每次计算每一层的边界low = 2^n，high = 2^n+1 -1 由于由每个子节点算出的父节点parent其位置和正常这一层的顺序位置一定是对称的
    //-我们需要利用high到parent的距离来算
    //-所以坐标应该转换成 parent = low + （high - parent）
    vector<int> pathInZigZagTree(int label) {
        vector<int> res = {label};
        computeDepth(label);
        //-计算当前节点的深度
        while(label!=1){
            label = label/2;
            int depth = computeDepth(label);
            int low,high;
            computeBound(depth, low, high);
            label = low + (high-label);
            res.push_back(label);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    int computeDepth(int label){
        int temp = (int)(log2(label));
        cout<<temp<<endl;
        return temp;
    }
    void computeBound(int depth, int &low, int& high){
        low = (int)pow(2,depth);
        high = (int)pow(2,depth+1) - 1;
    }
};