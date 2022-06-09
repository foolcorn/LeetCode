#include "utils.h"
// *假设nums是循环数组，返回nums中每个元素的下一个最大元素，找不到就返回-1
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> temp(nums);
        temp.insert(temp.end(),nums.begin(),nums.end());
        int size = (int)nums.size();
        vector<int> res(size,-1);
        vector<int> vstack;
        for(int i = temp.size()-1; i>=0;--i){
            while(!vstack.empty()&&temp[i]>=vstack.back()){
                vstack.pop_back();
            }
            res[i%size] = vstack.empty() ? -1 : vstack.back();
            vstack.push_back(temp[i]);
        }
        return res;
    }
};