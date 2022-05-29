#include "utils.h"
// * 珂珂吃香蕉，
// *n堆香蕉，第i堆中有 piles[i]根香蕉，
// *吃香蕉的速度为k，选择其中一堆吃掉k根，少于k根按k算
// *返回她可以在 h 小时内吃掉所有香蕉的最小速度 k
class Solution {
private:
    vector<int> nums;
public:
    //-计算以k的速度吃完要多少小时
    int eatHour(int k){
        int hour = 0;
        for(int i = 0;i<nums.size();++i){
            if(nums[i]%k == 0){
                hour += nums[i]/k;
            }else{
                hour += nums[i]/k+1;
            }
        }
        return hour;
    }
    //-速度k越快,eathour就越小，以k为x轴左小右大进行分析
    //-在k映射到相同的eathour时，要找到最左边的eathour，因为hour越左，k越小
    //-所以==的时候，收缩右边界。
    //-k和eathour是反比关系，当eathour>h时不更新right而是left
    int minEatingSpeed(vector<int>& piles, int h) {
        nums = piles;
        int left = 1;int right = 1000000000;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(eatHour(mid)>h){
                left = mid+1;
            } else if(eatHour(mid)<=h){
                right = mid-1;
            }
        }
        return left;
    }
};