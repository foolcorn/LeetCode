#include "utils.h"
// *返回只有k个数的组合（子集）
class Solution {
private:
    vector<vector<int>> res;
    int k;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i = 1;i<=n;++i){
            nums.push_back(i);
        }
        vector<int> temp;
        this->k = k;
        traceback(nums,temp,0);
        return res;
    }
    void traceback(vector<int> &nums, vector<int> &temp, int start){
        if(temp.size() == k){
            res.push_back(temp);
        }
        for(int i = start;i<nums.size();++i){
            temp.push_back(nums[i]);
            traceback(nums, temp, i+1);
            temp.pop_back();
        }
    }
};