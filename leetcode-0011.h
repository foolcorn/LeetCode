#include "utils.h"
// *盛水最多的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        //-使用双指针往中心收缩
        int left = 0;
        int right = height.size()-1;
        int res = 0;
        while(left < right) {
            //-计算当前的容量
            int cap = (right-left)*min(height[left], height[right]);
            res = max(res, cap);
            //-如果移动更高的边，矩形的面积依旧收到更小边的制约，那么移动高的边就没有意义了。
            //-如果移动矮的边，反而会有新的边更大，从而有更大面积的可能性
            if(height[left]>height[right]){
                --right;
            }else{
                ++left;
            }
        }
        return res;
    }
};
