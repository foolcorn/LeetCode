#include "utils.h"
// *有重复元素不可重复取的组合
class Solution {
private:
    vector<vector<int>> res;
    vector<int> temp;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //-有重复元素必须先排序
        sort(nums.begin(), nums.end());
        traceback(nums,0);
        return res;
    }

    void traceback(vector<int>& nums, int start){
        res.push_back(temp);
        for(int i = start; i<nums.size();++i){
            //-取过的元素不再取，如果有重复就跳过
            if(i>start && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            traceback(nums,i+1);
            temp.pop_back();
        }
    }
};
