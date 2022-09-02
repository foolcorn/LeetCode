#include "utils.h"
// *两数之和（数组无序）
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nmap;
        //-使用hash存元素和索引
        for(int i = 0; i <nums.size(); ++i) {
            int temp = target-nums[i];
            //-如果查到有对称元素，返回两者索引
            if(nmap.count(temp)>0){
                return {i,nmap[temp]};
            }
            //-查不到就把当前元素加入map
            nmap[nums[i]] = i;
        }
        return{-1, -1}
    }
};
