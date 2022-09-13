#include "utils.h"
// *青蛙过河
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        //-dp数组的含义：i是现在所处的石子编号，k是上一次跳跃的距离
        vector<vector<bool>> dp(n, vector<int>(n));
        dp[0][0] = true;
        //- 优化： 第i个石子 与第 i-1 个石子距离超过 i 时，青蛙必定无法到达终点
        for (int i = 1; i < n; ++i) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }
        for (int i = 1; i < n; ++i) {//- 现在所处的石子位置（索引）
            for (int j = i - 1; j >= 0; --j) {//- 上一次青蛙所处的石子位置（索引）
                int k = stones[i] - stones[j];//-上一次跳跃的距离
                if (k > j + 1) {//-如果跳不了就说明所有情况都无法成功，直接break
                    break;
                }
                //- 如果上一次跳跃距离 为 k-1,k,k+1 三者之一，则dp[i][k]可达
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};