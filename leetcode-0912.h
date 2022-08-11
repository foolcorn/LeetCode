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

class Solution {
    vector<int> temp;
public:
    //-实现一个归并排序
    vector<int> sortArray(vector<int>& nums) {
        temp = vector<int>(nums.size(),0);
        sort(nums,0,nums.size()-1);
        return nums;
    }
    void sort(vector<int>& nums,int low, int high){
        if(low == high){
            return;
        }
        int mid = low+(high-low)/2;
        sort(nums, low, mid);
        sort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }

    void merge(vector<int>& nums,int low, int mid,int high){
        for (int i = low; i <= high; i++) {
            temp[i] = nums[i];
        }
        int left = low;
        int right = mid+1;
        for (int i = low; i <= high; i++) {
            if(left == mid+1){
                nums[i] = temp[right++];
            }else if(right == high+1){
                nums[i] = temp[left++];
            }else if (temp[left]>temp[right]) {
                nums[i] = temp[right++];
            }else{
                nums[i] = temp[left++];
            }
        }
    }
};