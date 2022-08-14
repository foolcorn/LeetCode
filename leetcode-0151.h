#include "utils.h"
// * 颠倒字符串中的单词
class Solution {
public:
    string reverseWords(string s) {
        //-先反转整个字符串
        int left = 0;
        int right = s.size()-1;
        while(left < right) {
            swap(s[left++],s[right--]);
        }
        int i =0;
        int start = 0;
        //-逐个翻转单词
        while(i<s.size()) {
            if(s[i] == ' ' || i == s.size()-1) {
                //-翻转单词
                left = start;
                right = s[i] == ' '?i-1:i;
                while(left < right) {
                    swap(s[left++],s[right--]);
                }
                start = i+1;
            }
            ++i;
        }
        return s;
    }
};