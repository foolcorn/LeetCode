#include "utils.h"
// *预测赢家
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<pair<int,int>>> dp(size,vector<pair<int,int>>(size));
        for (int i = 0; i < size;++i){
            dp[i][i].first = nums[i];
            dp[i][i].second = 0;
        }
        for (int i = size - 2; i >= 0; --i){
            for (int j = i+1; j <size;++j){
                dp[i][j].first = max(nums[i]+dp[i+1][j].second,nums[j]+dp[i][j-1].second);
                //-如果选左边利益更大
                if(dp[i][j].first == nums[i]+dp[i+1][j].second){
                    //-后选的只能面临右边先选的局面
                    dp[i][j].second = dp[i+1][j].first;
                }else{
                    dp[i][j].second = dp[i][j-1].first;
                }
            }
        }
        return dp[0][size-1].first>dp[0][size-1].second;
    }
};

