#include "utils.h"
// *删除数组中所有等于val的元素
class Solution {
public:
    //-双指针，left指向可以插入的位置，right在前面不断地判断是不是==val。
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = 0;
        while (right<nums.size()){
            if(nums[right]==val){
                ++right;
            }else {
                //-如果不是val,就把当前的right移到合适的插入位置,左右指针同时前进
                nums[left] = nums[right];
                ++left;
                ++right;
            }
        }
        return left;
    }
};