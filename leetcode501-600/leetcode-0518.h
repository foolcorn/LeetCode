#include "utils.h"
// * 零钱兑换2：这是一个完全背包类型
// * 每个面额无限硬币，返回可以凑出amount的所有组合数
class Solution {
    vector<int> coins;
    vector<vector<int>> memo;
public:
    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        memo = vector<vector<int>>(coins.size(),vector<int>(amount+1,-1));
        return traceback(coins.size()-1,amount);
    }
    //-p表明了接下来可以选择的硬币种类的范围为[0..p],cap是剩余金额量
    int traceback(int p,int cap){
        if(p<0){
            return 0;
        }
        if(cap==0){
            return 1;
        }
        if(memo[p][cap]!=-1){
            return memo[p][cap];
        }
        //-如果p已经不能放了
        if(cap<coins[p]){
            memo[p][cap] = traceback(p-1,cap);
            return memo[p][cap];
        }
        //-尝试在新的容量里放p位置的coin，要么继续从p里选硬币，要么以后再也不选p了，两种可能的组合数加起来
        memo[p][cap] = traceback(p,cap-coins[p])+traceback(p-1,cap);
        return memo[p][cap];
    }
};