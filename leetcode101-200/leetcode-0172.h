#include "utils.h"
// *计算阶乘有几个零
class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0){return 0;}
        return n/5+trailingZeroes(n/5);
    }
};
class Solution2 {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(long divisor= n;divisor>0;divisor/=5){
            res+=divisor/5;
        }
        return res;
    }
};
class Solution1 {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(long divisor= 5;divisor<=n;divisor*=5){
            res+=(long)n/divisor;
        }
        return res;
    }
};
class Solution0 {
public:
    int trailingZeroes(int n) {
        int res = 0;
        long divisor = 5;
        while(divisor<=n){
            res+=(long)n/divisor;
            divisor*=5;
        }
        return res;
    }
};
