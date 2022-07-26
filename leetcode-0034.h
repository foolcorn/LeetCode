 n
 // *二分查找数组中target的上下界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int down = findDown(nums,target);
        int up = findTop(nums,target);
        return {down,up};
    }
    //-找左边界
    int findDown(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        while(left<right){
            int mid = left + (right-left)/2;
            if(nums[mid]<target){
                left = mid+1;
            }else if(nums[mid]>= target){
                right = mid;//-如果找到target会执行这个分支来收缩右边界，直到收缩到最左边一个target为止
            }
        }
        //-由于题目要求如果target不在nums中,左边界就会一直收缩到越界right，就返回-1,所以加个判断
        //-如果right一直没动，left可能会越界到nums.size(),如果right有动，那么left越界后==right，nums[right]有可能等于target
        //-需要判断一下这两种情况也就是break的时候，右边界要么是nums.size，要么有可能是target也有可能不是
        if(right==nums.size()||nums[right]!=target){
            return -1;
        }
        //-如果找得到target，右边界会往左收缩，且永远不会搜索过头
        return right;
    }
    //-找右边界
    int findTop(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size();
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>target){
                right = mid;
            }else if(nums[mid]<=target){
                left = mid+1;//-如果找到target会执行这个分支来收缩左边界，直到收缩到最右边target的下一个为止
            }
        }
        //-如果找不到target,且左边界一直没动==0，target始终小于nums[mid],右边界会一直收缩到0,且nums[0]必然不是target
        //-如果target不是始终小于nums[mid],那么就有可能left动。
        //-此时需要看break的时候，left==right，如果是由right=mid来结束循环，看上面的ifelse，必不可能==target
        //-如果最后是由left = mid+1来结束循环，left或者right的值必不为target，但是上一个left有可能是
        //-用上一个mid=left-1或者right（==left） -1来判断
        if(left == 0||nums[left-1]!=target){
            return -1;
        }
        //-如果找到target，由于左边界会一直往右收缩，直到收缩到最右边target的下一个为止
        //-当left==target，right=left+1!=target这个情况就会搜寻过头，所以返回left-1
        return left-1;
    }
};
//-总结最后的规律，
//-找左边界，break的时候，left==right，此时终态可能是target也可能不是，还有可能是越上界，判断这三种情况即可，
// -后两种返回-1，第一种返回left或者right
//-找右边界，break的时候left==right,此时终态必不等于target，但是left的上一个left-1状态可能是target也可能不是，还有可能终态到下界0,
//-判断三种状态，后两种返回-1，第一种返回left-1和right-1都行

