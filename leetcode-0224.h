#include "utils.h"
// *基本计算器1，表达式包括加减和括号
class Solution {
public:
    int calculate(string s) {
        deque<char> str(s.begin(),s.end());
        return traceback(str);
    }
    int traceback(deque<char> &str){
        vector<int> vstack;
        int num = 0;
        char lastoperator = '+';
        while(!str.empty()){
            char c = str.front();
            str.pop_front();
            //-如果是括号,递归
            if(c == '('){
                num = traceback(str);
            }
            //-如果是数字,累计
            else if(isdigit(c)){
                num = num * 10 + (c-'0');
            }
            //-如果是空格跳过
            else if(c == ' '){
                continue;
            }
            //-如果是右括号，返回
            else if(c == ')'){
                vstack.push_back(lastoperator == '-'?-num:num);
                return accumulate(vstack.begin(),vstack.end(),0);
            }
            //-如果是运算符
            else{
                switch(lastoperator){
                    case '+':
                        vstack.push_back(num);num = 0;lastoperator = c;break;
                    case '-':
                        vstack.push_back(-num);num = 0;lastoperator = c;break;
                }
            }
        }
        vstack.push_back(lastoperator == '-'?-num:num);
        //-如果程序走到这里就是最外层递归结束了,直接计算累计和
        return accumulate(vstack.begin(), vstack.end(),0);
    }
};