#include "utils.h"
// *全排列
class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(),false);
        vector<int> temp;
        traceback(nums, temp);
        return res;
    }
    void traceback(const vector<int> &nums,vector<int> &temp){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<nums.size();++i){
            if(used[i]){
                continue;
            }
            temp.push_back(nums[i]);
            used[i] = true;
            traceback(nums, temp);
            used[i] = false;
            temp.pop_back();
        }
    }
};