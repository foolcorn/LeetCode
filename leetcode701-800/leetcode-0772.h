#include "utils.h"
// *基本计算器 3 加减乘除和括号
class Solution {
public:
    //-构造一个函数专门用来处理加减乘除，通过上一个操作符，和新的num，从而更新栈，所以必须引用传值。
    //-思路：如果是左括号，递归，并获得返回值，此时更新num，如果是右括号，把最后一个数压入栈。如果是数字就累计
    //-当deque空的时候就和遇到右括号一样，把最后一个数压入栈，最后计算栈的总和。
    int calculate(string s) {
        deque<char> str(s.begin(),s.end());
        return traceback(str);
    }
    void dealoperator(char lastoperator,vector<int>& vstack,int num){
        switch(lastoperator){
            case '+':
                vstack.push_back(num);break;
            case '-':
                vstack.push_back(-num);break;
            case '*':{
                int temp = vstack.back()*num;
                vstack.pop_back();
                vstack.push_back(temp);break;}
            case '/':{
                int temp = vstack.back()/num;
                vstack.pop_back();
                vstack.push_back(temp);break;}
        }
    }
    int traceback(deque<char>& str){
        int num = 0;
        char lastoperator = '+';
        vector<int> vstack;
        while(!str.empty()){
            char c = str.front();
            str.pop_front();
            if(c == '('){
                num = traceback(str);
            }else if(isdigit(c)){
                num = num * 10 + (c-'0');
            }else if(c == ')'){
                dealoperator(lastoperator,vstack,num);
                return accumulate(vstack.begin(), vstack.end(),0);
            }
            else{
                dealoperator(lastoperator,vstack,num);
                lastoperator = c;
                num = 0;
            }
        }
        dealoperator(lastoperator,vstack,num);
        return accumulate(vstack.begin(), vstack.end(),0);
    }
};