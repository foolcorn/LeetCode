#include "utils.h"
// *斐波那契数列
class Solution {
public:
    int fib(int n) {
        if(n<2){
            return n;
        }
        int val1 = 1;
        int val0 = 0;
        for(int i = 2;i<n;++i){
            int val2 = val1+val0;
            val0 = val1;
            val1 = val2;
        }
        return val1+val0;
    }
};