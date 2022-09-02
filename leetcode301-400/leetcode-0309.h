#include "utils.h"
// *股票交易，不限次数，含交易冷冻期一天
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        //-如果天数小于两天等于0，买卖至少要两天
        if(days == 0||days == 1){
            return 0;
        }
        //-可以无限次交易
        int dp[days][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        //-因为存在i-2，所以baseclass应该包括i=1
        dp[1][0] = max(0,prices[1]-prices[0]);
        dp[1][1] = max(-prices[0],-prices[1]);
        for(int i = 2; i < days; ++i){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            //-买入的话，应该取dp[i-2]
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);
        }
        return dp[days-1][0];
    }
};