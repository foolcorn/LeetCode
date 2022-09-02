#include "utils.h"
// *按权重随机选择，给定w，w[i]指i元素的权重，考虑到在有权重的情况下，如何随机选择出一个元素
class Solution {
    vector<int> preSum;
public:
    Solution(vector<int>& w) {
        preSum = vector<int>(w.size()+1,0);
        //-前缀和数组
        for(int i = 1;i<=w.size(); ++i){
            preSum[i] = preSum[i-1]+w[i-1];
        }
    }
    int pickIndex() {
        //-随机生成下标,前缀和的末尾元素大小指示了虚拟数组的长度n，rand生成0~n-1的随机数，所以要+1
        int target = (rand() % preSum.back())+1;
        //-找到prsum中大于该下标的第一个元素
        int left = 0;
        int right = preSum.size();
        while(left<right){
            int mid = left+(right-left)/2;
            if(preSum[mid]>=target){
                right = mid;
            }else if(preSum[mid]<target){
                left = mid+1;
            }
        }
        //-题目要求返回的下标编号是从0开始的,所以要-1
        return left-1;
    }
};