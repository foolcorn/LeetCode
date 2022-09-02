#include "utils.h"
// *删除有序数组的重复项
class Solution {
public:
    //-双指针，left指向上一的不重复元素，right在前面不断和left匹配。
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0||nums.size() == 1){
            return nums.size();
        }
        int left = 0;
        int  right = 1;
        while(right < nums.size()){
            if(nums[right]==nums[left]){
                //-一直重复,left不动,right前进
                ++right;
            }else {
                //-left先指向插入位置
                ++left;
                nums[left] = nums[right];
                //-right继续前进
                ++right;
            }
        }
        return left+1;
    }
};