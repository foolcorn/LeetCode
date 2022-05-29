#include "utils.h"
// *给定nums，返回乘积严格小于k的连续子数组的数量，1<=nums[i]<=1000
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int window = 1;
        int count = 0;
        while(right < nums.size()){
            int temp = nums[right];
            window*=temp;
            while(window>=k&&left<=right){
                window/=nums[left];
                ++left;
            }
            count += right-left+1;
            ++right;
        }
        return count;
    }
};