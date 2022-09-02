#include "utils.h"
// *将nums分割成m个非空的连续数组，使其各自和的最大值最小
class Solution {
public:
    int computeDays(vector<int>& nums, int w){
        int days = 1;
        int lessweight = w;
        for(int i = 0;i<nums.size();++i){
            if(nums[i]<=lessweight){
                lessweight-=nums[i];
            }else{
                ++days;
                lessweight = w-nums[i];
            }
        }
        return days;
    }
    //-思路，转换成二分搜索最低负载的问题，每个子数组各自和的最大那个值就是负载，因为最多只能装最大子数组那么多重量的货物。
    //-我们要让负载最小，同时还得满足要==m天运完
    //-相当于m就是指定天数，然后船每次运负载量（和的最大值）的货物，只要在m天运完的最低负载，就是和的最大值的最小情况
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        while(left < right) {
            int mid = left + (right-left)/2;
            if(computeDays(nums,mid)<=m){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};