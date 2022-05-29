#include "utils.h"
// *买卖股票最大利润，不限次数，有手续费fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int days = prices.size();
        int profit[days][2];
        profit[0][0] = 0;
        profit[0][1] = -prices[0]-fee;
        for(int i = 1;i<days;++i){
            profit[i][0] = max(profit[i-1][0],profit[i-1][1]+prices[i]);
            //-买入的时候减去手续费
            profit[i][1] = max(profit[i-1][1],profit[i-1][0]-prices[i]-fee);
        }
        return profit[days-1][0];
    }
};