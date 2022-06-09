#include "utils.h"
// *给定lower和upper，计算nums中值在边界中的区间和个数
class Solution {
private:
    int lowbound;
    int upbound;
    vector<long> temp;//-归并临时数组
    int res;//-全局答案
public:
    //-思路构建前缀和数组，为什么这题可以转换成归并来做？
    //-首先归并是分治算法：这题为什么可以用分治？我们把nums变成前缀和数组。我们要遍历所有的区间和可能
    //-怎么才能把这种遍历从on2变成ologn？用分治法不断把前缀和进行分割，直到只有一个元素。
    //-然后往上回溯，也就是merge的过程，其实我之前对于归并的理解还不够深刻，不要把merge狭义理解为就是归并排序的合并过程。
    //-merge本质上是一个分治递归的后序回溯过程，我们在这个过程中，由于左右数组的特性，右数组的前缀和元素一定在左数组元素的右边。
    //-相当于对于左数组的每个元素ele1，都可以用右边的某个元素ele2减ele1得到一个区间和，来判断边界，但是，这样遍历还是会超时。
    //-所以还要在分治的过程中加入归并排序，意味着左右两个数组是连续有序的，而我们用右边数组连续有序这个特性，
    //-对于每个ele1，我们在右边直接找到ele2可能的上边界和下边界，然后两者相减就可以直接得到符合条件的区间和数量。
    //-而对于左数组有序递增的特性，我们可以在遍历每个ele1的时候，直接复用上一轮迭代后的ele2边界，在这个基础上继续递增，而不用每次都从头开始
    //-还有最后一点，前缀和要用long类型来存，否则可能溢出
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        //-全局边界
        lowbound = lower;
        upbound = upper;
        //-初始化temp
        temp = vector<long>(nums.size()+1, 0);
        //-构造前缀和数组
        vector<long> presum(nums.size()+1,0);
        for(int i = 1;i<=nums.size();++i){
            presum[i] = (long)presum[i-1]+(long)nums[i-1];
        }
        mergesort(presum,0,presum.size()-1);
        return res;
    }
    //-以下是归并框架
    void mergesort(vector<long>& nums, int low, int high){
        if(low == high){
            return;
        }
        int mid = low + (high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    void merge(vector<long>& nums, int low, int mid, int high){
        for(int i = low;i<= high;++i){
            temp[i] = nums[i];
        }
        //-这里对于左边的每个ele1，求个右边ele2的边界值，并更新答案
        int ele2_low_bound = mid+1;//-从右数组首元素开始
        int ele2_up_bound = mid +1;//-为什么这两个索引可以写在外面，而不是对于每个ele1都从头开始遍历？
        //-同样因为归并的性质，左数组是有序递增的，所以对于下一个ele1元素，其右边的ele2边界不可能小于之前的边界，否则肯定不满足条件
        for(int i = low;i<mid+1;++i){
            int ele1 = nums[i];
            //-因为边界是闭区间，所以包括lowbound，更新ele2_low_bound到==lowbound为止
            while(ele2_low_bound<=high&&nums[ele2_low_bound]-ele1<lowbound){
                ++ele2_low_bound;
            }
            //-同理，边界需要包括upbound，更新ele2_up_bound到==upbound为止，但是注意最后还有一次++
            while(ele2_up_bound<=high&&nums[ele2_up_bound]-ele1<=upbound){
                ++ele2_up_bound;
            }
            //-因为求上界的时候还有一次++，所以此处不用+1
            res+= ele2_up_bound-ele2_low_bound;
        }

        //-以下是传统归并，对当前的前缀和进行有序合并，留待下一轮
        int lp = low;
        int rp = mid+1;
        for(int i = low;i<=high;++i){
            if(lp == mid+1){
                nums[i] = temp[rp++];
            }else if(rp == high+1){
                nums[i] = temp[lp++];
            }else if(temp[lp]>temp[rp]){
                nums[i] = temp[rp++];
            }else {
                nums[i] = temp[lp++];
            }
        }
    }
};
