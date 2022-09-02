#include "utils.h"
// *买卖股票最大利润，只能交易一次
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //-不管是不是188的简化,总之先写出三个状态再化简
        int days = prices.size();
        //-第一个状态是天数,第二个状态是交易次数,第三个状态是股票持有状态
        int profit[days][2];
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        //-写出状态转移方程
        for(int i = 1;i<days;++i){
            profit[i][0] = max(profit[i-1][0],profit[i-1][1]+prices[i]);
            profit[i][1] = max(profit[i-1][1],-prices[i]);
        }
        return profit[days-1][0];
    }
};