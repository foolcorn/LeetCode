#include "utils.h"
// *最长回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for(int i = 0;i<s.size(); ++i){
            string s1 = findSubStr(s,i,i);
            string s2 = findSubStr(s,i,i+1);
            string maxs = s1.size()>s2.size() ? s1 : s2;
            res = maxs.size()>res.size() ? maxs : res;
        }
        return res;
    }
    string findSubStr(const string&s, int i ,int j){
        while(i>=0&&j<s.size()&&s[i] == s[j]){
            --i;
            ++j;
        }
        return s.substr(i+1,j-i-1);
    }
};