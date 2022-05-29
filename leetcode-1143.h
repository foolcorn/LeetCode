#include "utils.h"
// *最长公共子序列 返回text1和text2最长公共子序列长度，找不到就返回0 66%
class Solution {
    string s1;
    string s2;
    vector<vector<int>> memo;
public:
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1;
        s2 = text2;
        memo = vector<vector<int>>(s1.size(),vector<int>(s2.size(),-1));
        return traceback(s1.size()-1,s2.size()-1);
    }
    // !traceback代表了到p1，p2为止的最长序列长度
    int traceback(int p1, int p2){
        if(p1<0||p2<0){
            return 0;
        }
        if(memo[p1][p2]!=-1){
            return memo[p1][p2];
        }
        //-如果两个字符相等，加入子序列;
        if(s1[p1] == s2[p2]){
            memo[p1][p2] = 1+traceback(p1-1,p2-1);
            return memo[p1][p2];
        }
            //-如果两个字符串不等,那么尝试抛弃任意一个首元素继续匹配
        else {
            int res1 = traceback(p1,p2-1);
            int res2 = traceback(p1-1,p2);
            memo[p1][p2] = max(res1,res2);
            return memo[p1][p2];
        }
    }
};