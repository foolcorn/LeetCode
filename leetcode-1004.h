#include "utils.h"
// *最大连续1的个数
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //-重新定义题目,转换为对于每一个右端点,都找到一个左右端点之间0个数小于等于k的最小左端点
        int leftsum = 0;
        int rightsum = 0;
        int left = 0;
        int right = 0;
        int maxlength = 0;
        while(right < nums.size()) {
            rightsum+=1-nums[right];
            while(leftsum < rightsum-k) {//-说明左右端点之间多于k个0
                leftsum+=1-nums[left];
                ++left;
            }
            maxlength = max(maxlength,right-left+1);
            ++right;
        }
        return maxlength;
    }
};