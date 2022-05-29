#include "utils.h"
// *将数组nums划分为k个相等和的子集
class Solution {
private:
    string used;
    int target;
    unordered_map<string, bool>memo;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //-先写思路吧，我们划分k个相等子集，意味着我们要尝试让nums的元素一个个放入桶去尝试。
        //-那么可以借鉴回溯的框架，我们写个递归，每次递归开始，重置桶，然后一个个放入元素，如果该桶最后能填满，
        //-就进入新的一轮递归，重置桶，然后从0开始遍历。
        //-需要有几个参数来辅助，used(使用string 位图)，标示哪些元素之前已经入桶了，就不能再入。target，指示每个桶应该装多少
        //-如果加入当前元素>target,就不入桶
        //-使用memo来保存每次大递归完（装满一个bucket后）在这个基础上下一轮大递归的结果，注意不是保存每次小递归的结果。
        //-bucketless,指示还剩下几个桶没装满。
        //!注意，我最后还是超时了，还有最关键的两点，一个是把nums倒序排列，一个是用start来标识小递归的开始坐标
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum% k!= 0){
            return false;
        }
        target = sum/k;
        used = string(nums.size(),'0');
        sort(nums.rbegin(),nums.rend());
        return  traceback(0, k,0,nums);
    }
    bool traceback(int start,int bucketless,int bucket,vector<int>& nums){
        //-如果装满所有桶就返回正确
        if(bucketless == 0){
            return true;
        }
        //-判断当前桶有没有满
        if(bucket == target){
            //-剩余桶数量减少,重置bucket
            memo[used] = traceback(0,bucketless-1,0,nums);
            return memo[used];
        }
        if(memo.count(used)>0){
            return memo[used];
        }
        //-尝试装现在的桶
        for(int i = 0;i<nums.size();++i){
            //-如果元素被用了就跳过
            if(used[i]=='1'){
                continue;
            }
            //-如果元素装不下就跳过
            if(bucket+nums[i]>target){
                continue;
            }
            //-尝试加入该桶
            used[i] = '1';
            if(traceback(i+1,bucketless,bucket+nums[i],nums)){
                return true;
            }
            used[i] = '0';
        }
        //-遍历完所有元素都没法返回true,那么就返回false
        return false;
    }
};