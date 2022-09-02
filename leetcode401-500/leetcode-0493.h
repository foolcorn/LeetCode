#include "utils.h"
// *给定数组nums，求翻转对的数量
// *翻转对的定义: i<j&& nums[i] > 2*nums[j]
class Solution {
private:
    vector<int> temp;
    int res;
public:
    //-思路：使用分治思想，先拆分数组，然后利用左右数组判断左数组的元素ele1是否是右ele2的两倍
    //-同时，可以利用数组的有序性，重用之前的边界
    int reversePairs(vector<int>& nums) {
        //-扩张数组
        temp.resize(nums.size(),0);
        mergesort(nums,0,nums.size()-1);
        return res;
    }
    void mergesort(vector<int>& nums, int low, int high) {
        if(low == high){
            return;
        }
        int mid = low + (high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    void merge(vector<int>& nums,int low, int mid, int high){
        for(int i = low; i <= high; ++i){
            temp[i] = nums[i];
        }
        int rightbound = mid + 1;
        for(int i = low; i <= mid; ++i){
            long ele1 = (long)nums[i];
            while(rightbound<=high&&ele1>(long)2*nums[rightbound]){
                ++rightbound;
            }
            res += rightbound-mid-1;
        }
        int lp = low;
        int rp = mid+1;
        for(int i = low;i<=high;++i){
            if(lp == mid+1){
                nums[i] = temp[rp++];
            }else if(rp == high+1){
                nums[i] = temp[lp++];
            }else if(temp[lp]>temp[rp]){
                nums[i] = temp[rp++];
            }else{
                nums[i] = temp[lp++];
            }
        }
    }
};