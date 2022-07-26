#include "utils.h"
// *求二进制数中位1的个数
class Solution {
public:
    //-思路：n&n-1可以去除二进制串的末尾1
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n!=0){
            n = n&(n-1);
            ++res;
        }
        return res;
    }
};