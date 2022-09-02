#include "utils.h"
// *将所有零元素移到末尾
class Solution {
public:
    //-双指针，left指向可以插入的位置，right在前面不断地判断是不是==0。
    void moveZeroes(vector<int>& nums) {
        //-使用双指针边走边交换
        int slow = 0;
        int fast = 0;
        while(fast < nums.size()){
            if(nums[fast] == 0){
                ++fast;
            }else{
                nums[slow] = nums[fast];
                ++fast;
                ++slow;
            }
        }
        //-把最后的数字全部改成0
        for(;slow<nums.size(); ++slow){
            nums[slow] = 0;
        }
    }
};