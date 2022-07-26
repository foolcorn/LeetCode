#include "utils.h"
// *给定0~n-1一共n个气球，每次选择戳破一个气球i，则可以获得硬币=num[lefti]*nums[i]*nums[righti]个硬币
// *lefti是i左边第一个没被戳破的气球，righti是i右边第一个没被戳破的气球，如果两个下标越界，则nums[越界]==1
// *求能获得的最大硬币数
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = (int)nums.size();
        //-构造新的nums，将越界的两个假想的气球也加入
        vector<int> new_nums(size+2,1);
        for(int i =0;i<size;++i){
            new_nums[i+1] = nums[i];
        }
        //-(1)memo的意义是戳破i~j内所有气球,但是不包括i和j(开区间),可以获得的最大硬币数，所以memo的大小是size+2
        vector<vector<int>> memo(size+2,vector<int>(size+2,0));
        for(int i = memo.size()-1;i>=0;--i){//-(3)难点在这两个大循环怎么写，由于每个memo[i][j]都由其左边的memo和下边的memo计算得到
            for(int j = i+1;j<memo.size();++j){//-所以需要从下往上，从左往右进行遍历，而memo[i][j]（i==j，副对角线）是baseclass==0
                for(int k = i+1;k<j;++k){
                    //-(2)所以在i+1到j-1中找一个最大硬币的戳破选择k,由memo[i][k(k<j)]和memo[k(k>i)][j]计算得到
                    memo[i][j] = max(memo[i][j],memo[i][k]+memo[k][j]+new_nums[i]*new_nums[k]*new_nums[j]);
                }
            }
        }
        return memo[0][size+1];
    }
};
