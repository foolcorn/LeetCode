#include "utils.h"
// *零钱兑换：coins是不同的硬币面额，计算可以凑出amount的最小硬币个数 66%
class Solution {
    vector<int> memo;
public:
    int coinChange(vector<int>& coins, int amount) {
        //-随便一个负数都行
        memo = vector<int>(amount+1,-666);
        return sonProblem(coins, amount);
    }
    //-其实就是一维动态规划,dp只和剩余amount有关
    int sonProblem(vector<int>& coins, int amount){
        if(amount == 0){return 0;}
        if(amount <0){return -1;}
        if(memo[amount] != -666){
            return memo[amount];
        }
        int res = INT_MAX;
        for(int i = 0;i< coins.size();++i){
            //-做选择
            int temp = sonProblem(coins,amount-coins[i]);
            //-如果该选择凑不出amount,略过
            if(temp == -1){continue;}
            //-如果比当前答案更小，就更新最终答案
            if(temp+1<res){res = temp+1;}
        }
        //-最后更新memo，如果temp一直是-1，则res是不会变的，为intmax
        memo[amount] = (res == INT_MAX)?-1:res;
        return memo[amount];
    }
};