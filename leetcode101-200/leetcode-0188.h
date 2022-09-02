#include "utils.h"
// *买卖股票最大利润，不限交易次数
class Solution {
public:
    int nokprofit(vector<int> & prices){
        int days = prices.size();
        int profit[days][2];
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        for(int i = 1;i<days;++i){
            profit[i][0] = max(profit[i-1][0],profit[i-1][1]+prices[i]);
            profit[i][1] = max(profit[i-1][1],profit[i-1][0]-prices[i]);
        }
        return profit[days-1][0];
    }
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if(days == 0){
            return 0;
        }
        //-如果能交易无限次
        if(k>days){
            return nokprofit(prices);
        }
        int profit[days][k+1][2];
        //-先写k==0的baseclass
        for(int i = 0;i<days;++i){
            profit[i][0][0] = 0;
            profit[i][0][1] = INT_MIN;
        }
        //-在写k==1~k的baseclass
        for(int count = 1;count <= k;++count){
            profit[0][count][0] = 0;
            profit[0][count][1] = -prices[0];
        }
        for(int i = 1;i<days;++i){
            for(int count=1;count<=k;++count){
                profit[i][count][0] = max(profit[i-1][count][0],profit[i-1][count][1]+prices[i]);
                profit[i][count][1] = max(profit[i-1][count][1],profit[i-1][count-1][0]-prices[i]);
            }
        }
        return profit[days-1][k][0];
    }
};