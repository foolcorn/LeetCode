#include "utils.h"
// *假设从0~n的n+1个数取n个作为nums，找到丢失的那个数字
class Solution {
public:
    //-思路,将nums中每个元素和0~n进行异或，则只有丢失的那个数字不会重复
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = (int)nums.size();
        for(int i = 0;i<n;++i){
            res = res^i^nums[i];
        }
        res = res ^ n;
        return res;
    }
};