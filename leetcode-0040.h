#include "utils.h"
// *从candidates（有重复元素）中找到==target的组合
class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;
    int tar;
    int acsum;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        nums = candidates;
        tar = target;
        //-累计和
        acsum = 0;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        traceback(temp,0);
        return res;
    }
    void traceback(vector<int> &temp, int start){
        if(acsum == tar){
            res.push_back(temp);
        }
        //-其实这个也可以不用，略微剪枝吧
        if(acsum>tar){
            return;
        }
        for(int i = start;i<nums.size();++i){
            if(i>start && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            acsum+=nums[i];
            traceback(temp,i+1);
            acsum-=nums[i];
            temp.pop_back();
        }
    }
};