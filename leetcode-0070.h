#include "utils.h"
// *爬楼梯
class Solution {
private:
    vector<int> memo;
public:
    int climbStairs(int n) {
        memo.resize(n,-1);
        return traceback(n);
    }
    int traceback(int n){
        if(n<=2){
            return n;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        memo[n] = traceback(n-1)+traceback(n-2);
        return memo[n];
    }
};
