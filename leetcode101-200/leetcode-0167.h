#include "utils.h"
// *两数之和，数组有序，只存在唯一一个答案
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = (int)numbers.size()-1;
        while(left<right){
            int sum = numbers[left]+numbers[right];
            if(sum>target){
                --right;
            }else if(sum<target){
                ++left;
            }else{
                return {left+1,right+1};
            }
        }
        //-找不到返回-1,虽然题目说一定有答案
        return {-1,-1};
    }
};