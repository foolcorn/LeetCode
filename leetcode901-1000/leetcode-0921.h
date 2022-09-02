#include "utils.h"
// *给定括号串可能左右括号数量不匹配，可以插入左右括号，问最少插入次数使其合法
class Solution {
public:
    int minAddToMakeValid(string s) {
        int lessright = 0;
        int lessleft = 0;
        for(int i = 0;i<s.size();++i){
            char c = s[i];
            //-遇到一个左括号，意味着后面需要一个右括号
            if(c == '('){
                ++lessright;
            } else{//-遇到右括号就减少需要的量
                --lessright;
                //-考虑到没遇到左括号就出现右括号的情况，只能插入左括号
                if(lessright == -1){
                    lessright = 0;
                    ++lessleft;
                }
            }
        }
        return lessleft+lessright;
    }
};