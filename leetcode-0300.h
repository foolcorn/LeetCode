#include "utils.h"
// *找到数组最长严格递增子序列（不连续）81%
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        //-这里设置dp数组的意义是以i为end的递增子序列的最长长度
        vector<int> dp(size,1);
        for(int i = 1;i<size;++i){
            int sumtemp = INT_MIN;
            //-对于每一个i的end,从头开始遍历到i
            for(int j = 0; j<i;++j){
                if(nums[j]<nums[i]&&dp[j]>sumtemp){
                    sumtemp = dp[j];
                }
            }
            //-sumtemp是在i之前找到的终点比i小的最大的子序列长度,如果找不到就是int min
            //-如果找不到，就从当前i开始重新计算，所以为1，否则为之前子序列长度（sumtemp）加上自己（+1）
            dp[i] = sumtemp==INT_MIN?1:sumtemp+1;
        }
        int maxele = INT_MIN;
        //-最后遍历一遍以i为end的所有可能性
        for(auto &ele:dp){
            maxele = max(maxele, ele);
        }
        return maxele;
    }
};