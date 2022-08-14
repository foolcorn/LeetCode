#include "utils.h"
// *合并两个有序数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int tp = nums1.size()-1;
        while(tp>=0) {
            if(p1 == -1){
                nums1[tp--] = nums2[p2--];
            }else if(p2 == -1){
                nums1[tp--] = nums1[p1--];
            }else if(nums1[p1]<nums2[p2]){
                nums1[tp--] = nums2[p2--];
            }else{
                nums1[tp--] = nums1[p1--];
            }
        }
    }
};