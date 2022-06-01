#include "utils.h"
// *将数组升序排序
class Solution {
public:
    //-再写一遍快排吧
    vector<int> sortArray(vector<int>& nums) {
        shuffle(nums);
        fastsort(nums,0,nums.size()-1);
        return nums;
    }
    void fastsort(vector<int>& nums,int start,int end) {
        if(start>=end) {
            return;
        }
        int split = partition(nums,start,end);
        fastsort(nums,start,split-1);
        fastsort(nums,split+1,end);
    }
    static int partition(vector<int>& num,int start,int end) {
        int value = num[start];
        int left = start+1;
        int right = end;
        while(left <= right) {
            while(left <= end && nums[left]<=value){
                ++left;
            }
            while(right > start && nums[right]>value) {
                --right;
            }
            if(left >= right){
                break;
            }
            swap(nums[left],nums[right]);
        }
        swap(nums[start],nums[right]);
        return right;
    }
    static void shuffle(vector<int>& nums){
        random_shuffle(nums);
    }
};