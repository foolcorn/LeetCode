#include "utils.h"
// *无重复元素可重复取
class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;
    int tar;
    int acsum;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        tar = target;
        nums = candidates;
        //-依旧排序
        sort(nums.begin(),nums.end());
        vector<int> temp;
        traceback(temp,0);
        return res;
    }
    void traceback(vector<int> &temp, int start){
        //-累计和达到目标就更新res
        if(acsum == tar){
            res.push_back(temp);
            return;
        }
        if(acsum>tar){
            return;
        }
        for(int i = start;i<nums.size();++i){
            temp.push_back(nums[i]);
            acsum+=nums[i];
            traceback(temp,i);//-这里更新start并不是i+1
            temp.pop_back();
            acsum-=nums[i];
        }
    }
};