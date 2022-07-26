#include "utils.h"
// *给定nums，实现pick，使在nums中所有==target的元素中等概率地返回其中一个的索引
class Solution {
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    int pick(int target) {
        int count = 0;
        int res = 0;
        for(int i = 0; i < nums.size();++i){
            if(nums[i] == target){
                ++count;
                if(rand() % count == 0){
                    res = i;
                }
            }
        }
        return res;
    }
};