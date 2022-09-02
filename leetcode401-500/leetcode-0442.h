#include "utils.h"
// *nums所有整数在[1-n]范围，每个整数只出现一次或两次，找到所有出现两次的整数。
class Solution {
public:
    //-思路：原地哈希，将遍历每一个元素，将该元素放到对应下标上，使用交换法，
    //-之后再遍历一遍，记录那些不在下标上的元素，加入到res中
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i = 0;i<nums.size();++i){
            //-这个while而不是if很精髓，保证每个元素都能判断一次，即便交换的两个数是一样的数也可以
            while(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        vector<int>res;
        for(int i = 0;i<nums.size();++i){
            if(nums[i]!=i+1){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};