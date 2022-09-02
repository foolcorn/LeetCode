#include "utils.h"
// *打家劫舍2：房屋是环形数组，
// -思路，说明头尾房屋不能同时偷，既然也就两种情况。那就直接分两种情况讨论即可，要么不偷第一家，要么不偷最后一家，选一个max
class Solution {
public:
    int rob(vector<int>& nums) {
        int houses = nums.size();
        if(houses == 1){
            return nums[0];
        }
        if(houses == 2){
            return  max(nums[0],nums[1]);
        }
        //-不偷最后一家
        int profit1[houses-1];
        profit1[0] = nums[0];
        profit1[1] = max(nums[0],nums[1]);
        for(int i = 2; i < houses-1; ++i) {
            profit1[i] = max(profit1[i-1],profit1[i-2]+nums[i]);
        }
        //-不偷第一家
        int profit2[houses-1];
        profit2[0] = nums[1];
        profit2[1] = max(nums[1],nums[2]);
        for(int i = 3; i < houses; ++i) {
            profit2[i-1] = max(profit2[i-2],profit2[i-3]+nums[i]);
        }
        return max(profit1[houses - 2],profit2[houses -2]);
    }
};

