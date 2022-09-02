#include "utils.h"
// *括号匹配，给定s只包括 '('，')'，'{'，'}'，'['，']' ，判断是否合法
class Solution {
public:
    char getRight(char left){
        if(left == '('){return ')';}
        if(left == '{'){return '}';}
        if(left == '['){return ']';}
        return ' ';
    }
    bool isValid(string s) {
        vector<char> stack;
        bool sign = true;
        for(int i = 0;i<s.size();++i){
            //-遇到左括号入栈
            if(s[i] == '{'||s[i] == '('||s[i] == '['){
                stack.push_back(s[i]);
            }
            //-遇到右括号,判断栈头和右括号是否匹配,匹配就弹栈,否则直接return false
            else if(!stack.empty()&&getRight(stack.back()) == s[i]){
                stack.pop_back();
            }
            else{
                return false;
            }
        }
        //-还要排除只有左括号的情况
        if(!stack.empty()){
            sign = false;
        }
        return sign;
    }
};
