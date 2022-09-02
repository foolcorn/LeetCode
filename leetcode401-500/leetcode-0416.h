#include "utils.h"
// *判断是否能将数组分割成两个等和子集
class Solution {
public:
    //-将sum/2,使用01背包的思想来做
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        // sort(nums.begin(),nums.end());
        int half = sum/2;
        if(sum%2!=0){
            return false;
        } else{
            return makeDp(nums, half);
        }
    }

    bool makeDp(vector<int>& nums, int weight){
        int num = nums.size();
        //-二维dp,第一个维度是选择的物品范围为0..i,第二个维度是剩余的背包容量
        vector<vector<bool>> dp = vector<vector<bool>>(num+1,vector<bool>(weight+1, false));
        //-base class,剩余容量为0,则背包刚好装满
        for(int i =0;i<=num; ++i){
            dp[i][0] = true;
        }
        for(int i = 1;i<=num;++i){
            for(int j = 1;j<=weight;++j){
                //-如果剩余容量装不下第i个物品,就不放该物品,而是从之前0..i-1的范围内选
                //-注意nums[]的下标的i-1是第i个物品,因为二维循环的i是从1开始的
                if(j-nums[i-1]<0){
                    //-dp的i就是指第0..i的物品范围
                    dp[i][j] = dp[i-1][j];
                } else{
                    //-尝试放该物品和不放该物品两种选择
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[num][weight];
    }
};