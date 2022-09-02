#include "utils.h"
// *求结尾0的数量==k的阶乘有多少个
class Solution {
public:
    //-思路：二分搜索配合计算尾数零的函数
    int preimageSizeFZF(int k) {
        long left = 0;
        long right = LONG_MAX;
        while(left<right){
            long mid = left+(right-left)/2;
            if(computeZero(mid)>k){
                right = mid;
            }else if(computeZero(mid)<k){
                left = mid+1;
            }else{
                return 5;//-答案只可能是0或者5
            }
        }
        return 0;
    }
    //-这里的返回值类型必须是long,非常重要,如果是int会算错
    long computeZero(long n){
        long res = 0;
        for(long div = n;div>0;div/=5){
            res+=div/5;
        }
        return res;
    }
    long computeZero1(long n){
        if (n==0) return 0;
        return n/5+computeZero(n/5);
    }
};