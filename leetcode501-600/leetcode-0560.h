#include "utils.h"
// *-和为k的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //-前缀和降低时间复杂度的办法
        //-一维遍历数组，遍历的时候计算累计和
        //-在遍历的时候，使用一个map映射，每一种符合target的累计和（=当前累计和-k）有几个
        //-假设数组没有负数，也就是每次迭代的累计和都不一样，可以便于理解成：
        //-在每一次迭代的计算当前累计和，能不能在之前迭代记录的累计和里，找到一个=当前累计和-k的累计和存在，如果有
        //-++res_count,然后把本次迭代的累计和置1，代表有=该值的累计和存在，其实用set就可以实现
        //-为什么要用map不用set，有可能数组有负数，导致出现累计和重复的情况，所以用map++计录有几个符合条件的累计和存在
        unordered_map<int,int> sum;
        sum[0] = 1;
        int sumele = 0;
        int total = 0;
        for(int i = 0;i<nums.size();++i){
            sumele = sumele + nums[i];
            int temp = sumele-k;
            total += sum[temp];
            ++sum[sumele];
        }
        return total;
    }
};