#include "utils.h"
// *给定数组nums，给数组的每个数字之间添加'+'或者'-'构造成表达式，问结果==target的组合数有多少
class Solution {
    vector<unordered_map<int,int>> memo;//-二维动态规划的二维备忘录
public:
    //-思路：动态规划，对于每个数字位之前，对+-做选择，做了不同的选择，则对于剩余的数字位，需要满足一个更新后的target
    int findTargetSumWays(vector<int>& nums, int target) {
        memo.resize(nums.size(),unordered_map<int,int>());
        return traceback(nums,0,target);
    }
    //-返回数组以start开始,能构成less大小的不同组合数量
    int traceback(vector<int>& nums, int start,int less){
        if(start == nums.size()){//-如果走到头，而表达式可以满足target，就返回1
            return less == 0? 1:0;
        }
        if(memo[start].count(less)>0){
            return memo[start][less];//-为什么第二维要用map，因为有less可能是负数，二维数组没有负数下标
        }
        //-如果给start填加号，意味着剩余的数字构成的表达式只需要更小的target（减去当前的数字）
        int res1 = traceback(nums,start+1,less-nums[start]);
        //-如果给start填减号，意味着剩余的数字构成的表达式需要满足更大的target
        int res2 = traceback(nums,start+1,less+nums[start]);
        memo[start][less] = res1+res2;
        return memo[start][less];
    }
};