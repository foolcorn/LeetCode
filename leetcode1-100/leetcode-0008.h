#include "utils.h"
// *字符串转换整数
class Solution {
public:
    int myAtoi(string s) {
        bool flag = true;
        int i = 0;
        while(s[i] == ' '){++i;}
        if(s[i] == '-'){flag = false;}
        if(s[i] == '+'||s[i] == '-'){++i;}
        int sum = 0;
        while(i<s.size()){
            if(!isdigit(s[i])){break;}
            int temp = s[i] - '0';
            if(sum > INT_MAX/10||(sum == INT_MAX/10&&temp>7)){
                return flag? INT_MAX:INT_MIN;
            }
            sum = sum*10+temp;
            ++i;
        }
        return flag?sum:-sum;
    }
};