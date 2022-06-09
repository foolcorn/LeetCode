#include "utils.h"
// *给定num1是num2的子集，返回vector存所有num1的元素在num2中对应位置的下一个更大元素
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //-思路：使用单调栈，维护一个数组存所有nums2的下一个更大元素，再加个map映射val到index即可。
        unordered_map<int,int> mmap;
        vector<int> vstack;
        vector<int> nextEle2(nums2.size());
        for(int i = nums2.size()-1; i>=0; --i){
            mmap[nums2[i]] = i;
            while(!vstack.empty()&&vstack.back()<=nums2[i]) {
                vstack.pop_back();
            }
            nextEle2[i] = vstack.empty() ? -1 : vstack.back();
            vstack.push_back(nums2[i]);
        }
        vector<int> nextEle1;
        for(auto& ele:nums1){
            nextEle1.push_back(nextEle2[mmap[ele]]);
        }
        return nextEle1;
    }
};