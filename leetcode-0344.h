#include "utils.h"
// *反转字符串
class Solution {
public:
    //-双指针交换即可
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = (int)s.size()-1;
        char temp;
        while(left<right){
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            ++left;
            --right;
        }
    }
};