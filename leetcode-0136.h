#include "utils.h"
// *如果nums中所有数字都出现两次，只有一个数字出现一次，找出那个数字
class Solution {
public:
    //-每个数和自己异或等于0，每个数和0异或则等于该数，所以把数组所有元素异或即可
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int ele:nums){
            res = ele^res;
        }
        return res;
    }
};