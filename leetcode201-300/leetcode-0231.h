#include "utils.h"
// *判断一个数是不是2的幂次方
class Solution {
public:
    //-只要是2的幂次方，则转成二进制串的时候，只可能有一个1，其它全是0
    bool isPowerOfTwo(int n) {
        if(n == 0){return false;}
        return (n&(n-1)) == 0;
    }
};