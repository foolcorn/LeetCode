#include "utils.h"
// *接雨水
class Solution {
public:
    int trap(vector<int>& height) {
        //-左右双指针
        int left = 0;
        int right = height.size()-1;
        //-维护两个变量，分别为左右各自的maxheight
        int max_height_left = 0;
        int max_height_right = 0;
        int res = 0;
        while(left<right){
            //-左右更新当前最大高度
            max_height_left = max(max_height_left,height[left]);
            max_height_right = max(max_height_right,height[right]);
            //-双指针向内收缩,到break之前,会把所有格子都遍历一遍,
            //-对于每个格子的接雨水的容量只和较小的一边高度有关。
            if(max_height_left>max_height_right){
                res+=max_height_right-height[right];
                --right;
            }else{
                res+=max_height_left-height[left];
                ++left;
            }
        }
        return res;
    }

};