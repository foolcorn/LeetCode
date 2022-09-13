#include "utils.h"
// *判断字符串s能否由其一个子串重复多次构成
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};