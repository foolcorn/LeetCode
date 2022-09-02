#include "utils.h"
// *买卖股票最大利润，交易无限次数
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //-不限制交易次数
        int days = (int)prices.size();
        int profit[days][2];
        //-判断baseclass
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        for(int i = 1; i < days;++i){
            profit[i][0] = max(profit[i-1][0],profit[i-1][1]+prices[i]);
            profit[i][1] = max(profit[i-1][1], profit[i-1][0]-prices[i]);
        }
        return profit[days-1][0];
    }
};