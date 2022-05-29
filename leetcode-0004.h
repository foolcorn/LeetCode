#include "utils.h"
// *给定两个正序数组，返回这两个正序数组的中位数
class Solution {
private:
    vector<int> nums1;
    vector<int> nums2;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        //-先判断元素数量是单数还是双数
        if(size%2==0){
            return (findTopK(size/2)+findTopK(size/2+1))/2.0;

        }else{
            return findTopK(size/2+1);
        }

    }
    //-找第k小的数据
    int findTopK(int k){
        //-使用下标伪删除vector元素
        int begin1 = 0;
        int begin2 = 0;
        //-尺寸
        int size1 = nums1.size();
        int size2 = nums2.size();
        //-既然要从两个数组中找到在两个数组中第k小的数据
        //-那么就两个数组分别拿出k/2个元素来比较
        while (true){
            if(begin1==size1){
                //-数组1删除到空，从数组2取第k大的数据
                return nums2[begin2+k-1];
            }
            if(begin2==size2){
                //-数组2删除到空
                return nums1[begin1+k-1];
            }
            if(k == 1){
                return min(nums1[begin1],nums2[begin2]);
            }
            //-取第k/2大的数，下标为k/2-1
            int halfk = k/2-1;
            int index1 = begin1+halfk<size1 ? begin1+halfk : size1-1;
            int index2 = begin2+halfk<size2 ? begin2+halfk : size2-1;

            int ele1 = nums1[index1];
            int ele2 = nums2[index2];
            if(ele1<=ele2){
                //-说明到ele1最多也就是第k-1小的元素,于是把0-halfk(包括halfk，所以+1)的元素删掉
                k-=index1-begin1+1;
                begin1 = index1+1;
            }else{
                k-=index2-begin2+1;
                begin2 = index2+1;
            }
        }
    }
};