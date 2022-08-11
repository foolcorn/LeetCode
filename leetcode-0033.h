#include "utils.h"
// *搜索旋转排序数组
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return searchTrace(nums, 0,nums.size()-1, target);
    }
    int searchTrace(vector<int>& nums,int left,int right,int target) {
        // cout<<left<<"  "<<right<<endl;
        if(left>right){
            return -1;
        }
        int mid = left +(right-left)/2;
        int left_value = nums[left];
        int mid_value = nums[mid];
        int right_value = nums[right];
        //-判断三个标志位是否是target
        if(target == left_value){return left;}
        if(target == mid_value){return mid;}
        if(target == right_value){return right;}
        //-判断哪边是有序的
        //-如果左边有序
        if(left_value <mid_value){
            //-判断target是否在其中
            if(target>left_value&&target<mid_value){
                return searchTrace(nums,left+1,mid-1,target);
            }else{
                return searchTrace(nums,mid+1,right-1,target);
            }
        }else{
            //-判断target是否在其中
            if(target>mid_value&&target<right_value){
                return searchTrace(nums,mid+1,right-1,target);
            }else{
                return searchTrace(nums,left+1,mid-1,target);
            }
        }
    }
};