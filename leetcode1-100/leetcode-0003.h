#include "utils.h"
// *无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //-使用set当窗口，如果right遇到重复的，就收缩窗口更新left，让窗口pop_front直到窗口那个重复字符pop掉，让left指向下一位。
        //-期间不断更新maxlength，用当前的right-left+1
        int left = 0; int right = 0;
        unordered_set<char> window;
        int res = 0;
        while(right < s.size()){
            if(window.count(s[right]) == 0){
                window.insert(s[right]);
            }
            else{
                while(s[left]!=s[right]){
                    window.erase(s[left]);
                    ++left;
                }
                ++left;
            }
            res = max(res, right-left+1);
            ++right;
        }
        return res;
    }
};
