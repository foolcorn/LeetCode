#include "utils.h"
// *买卖股票最大利润，交易2次
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = (int)prices.size();
        //-细节:限定2次交易,但是维度设大一位为3
        //-2次交易，意味着k有三种状态：0,1,2;
        int profit[days][3][2];
        //-处理baseclass
        //-先处理k==0的情况，如果不持有股票就是0，如果没交易就持有股票是不可能，所以取intmin
        for(int i = 0;i<days;++i){
            profit[i][0][0] = 0;
            profit[i][0][1] = INT_MIN;
        }
        //-之后处理k==1和k==2的情况，可以根据后面写出来的递推式反推baseclass
        profit[0][1][0] = 0;
        profit[0][1][1] = -prices[0];
        profit[0][2][0] = 0;
        profit[0][2][1] = -prices[0];
        for (int i = 1; i < days; ++i) {
            profit[i][1][0] = max(profit[i-1][1][0],profit[i-1][1][1]+prices[i]);
            profit[i][1][1] = max(profit[i-1][1][1],profit[i-1][0][0]-prices[i]);
            profit[i][2][0] = max(profit[i-1][2][0],profit[i-1][2][1]+prices[i]);
            profit[i][2][1] = max(profit[i-1][2][1],profit[i-1][1][0]-prices[i]);
        }
        return profit[days-1][2][0];
    }
};