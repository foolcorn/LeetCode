#include "utils.h"
// * 返回区间内子数组的和
class NumArray {
    vector<int> presum;
public:
    NumArray(vector<int>& nums) {
        //-构造前缀和数组
        presum = vector<int>(nums.size()+1,0);
        for(int i=1;i<=nums.size();++i){
            presum[i] = presum[i-1]+nums[i-1];
        }
    }
    int sumRange(int left, int right) {
        //-presum 长度比 nums要长
        //-presum[left]的意义是nums[left]之前的所有元素的和，并不包括nums[left]
        //-求的区间是左闭右闭区间[left,right]的长度,所以right+1
        return presum[right+1] - presum[left];
    }
};
