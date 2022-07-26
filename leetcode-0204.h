#include "utils.h"
// *给定整数n，计算所有<n的质数的数量
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n,true);
        for(int i = 2;i*i<n;++i){
            if(isprime[i]){
                for(int j = i*i;j<n;j+=i){
                    isprime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i =2;i<n;++i){
            if(isprime[i])
                ++count;
        }
        return count;
    }
};