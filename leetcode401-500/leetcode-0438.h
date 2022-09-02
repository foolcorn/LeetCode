#include "utils.h"
// *匹配子串的排列
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //-和76的区别在于，76窗口可以有不在子串中的字符，但这题的窗口大小要收缩的和子串一样，
        //-所以收缩窗口时，判断收缩终止的条件不一样，这题收缩到size=子串len即可
        //-这题依旧要valid，判断字符串是否完全匹配
        int left = 0, right = 0;
        unordered_map<char, int> window, target;
        int valid = 0;int length = 0;
        vector<int> res;
        for (auto ele:p) {
            ++target[ele];
        }
        while (right < s.size()) {
            char c = s[right];
            ++right;
            ++length;
            if (target.count(c) > 0) {
                ++window[c];
                if (window[c] == target[c]) {
                    ++valid;
                }
            }
            while (length > p.size()) {
                char d = s[left];
                ++left;
                --length;
                if (window.count(d) > 0) {
                    if (window[d] == target[d]) {
                        --valid;
                    }
                    --window[d];
                }
            }
            if (valid == target.size()) {
                res.push_back(left);
            }
        }
        return res;
    }
};