#include "utils.h"
// *给定nums数组，求其所有子集
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        traceback(nums,temp,0);
        return res;
    }
    void traceback(vector<int>& nums, vector<int>& temp, int start){
        int length = (int)nums.size();
        res.push_back(temp);
        for(int i = start; i<length; ++i){
            temp.push_back(nums[i]);
            traceback(nums,temp,i+1);
            temp.pop_back();
        }
    }
private:
    vector<vector<int>> res;
};