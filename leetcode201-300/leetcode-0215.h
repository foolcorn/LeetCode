#include "utils.h"
// *给定数组找第k大的元素
class Solution {
public:
    //-使用快速选择法
    //-二分法是针对一个有序数组的查找，快选则是边排序，边找元素
    int findKthLargest(vector<int>& nums, int k) {
        shuffle(nums);
        int target = (int)nums.size()-k;
        int left = 0;
        int right = nums.size() - 1;
        while(left<=right){
            int p = partition(nums,left,right);
            if(target<p){
                right = p-1;
            }else if(target>p){
                left = p+1;
            }else {
                return nums[p];
            }
        }
        return -1;
    }
    //-洗牌
    void shuffle(vector<int> &nums) {
        random_shuffle(nums.begin(), nums.end());
    }
    int partition(vector<int>& nums, int start, int end){
        int value = nums[start];
        int i = start+1;
        int j = end;
        //-双指针指向同一个元素也要判断,因为不清楚这个元素是比value大还是小
        while(i<=j){
            //-这里用<=，说明此时num[i]一定小于等于value
            while(i<end&&nums[i]<=value){
                ++i;
            }
            //-这里用>,说明此时j一定能保证>value
            while(j>start&&nums[j]>value){
                --j;
            }
            //-经过++i和--j,一定能保证循环结束的时候，j指向的元素<=value
            if(i>=j){
                break;
            }
            swap(nums[i], nums[j]);
        }
        //-如果只有一个元素,i会越界,但是start不会,所以相当于自己和自己交换了,是安全的
        swap(nums[start], nums[j]);
        return j;
    }
};