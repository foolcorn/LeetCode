#include "utils.h"
// *打家劫舍1
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int length = (int)nums.size();
        //-dp数组的意义是到第i个房为止的最大收益
        int profit[length];
        profit[0] = nums[0];
        profit[1] = max(nums[0],nums[1]);
        for(int i =2;i<length;++i){
            profit[i] = max(profit[i-1],profit[i-2]+nums[i]);
        }
        return profit[length-1];
    }
};