#include "utils.h"
// *求数组的最大连续子数组和（有负数）88%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){return 0;}
        dp设置为,以i为终点的最大连续子数组和
        vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i = 1;i<n;++i){
            //-做选择,要么和上一个i连起来作为连续子数组,要么就自己从头开始
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        }
        //-遍历得到结果
        int res = INT_MIN;
        for(int i = 0;i<n;++i){
            res = max(res,dp[i]);
        }
        return res;
    }
};