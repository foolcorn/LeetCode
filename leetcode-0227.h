#include "utils.h"
// *基本计算器2，实现加减乘除(无括号)
class Solution {
public:
    int calculate(string s) {
        deque<char> str;
        for(char &c : s) {
            if(c!=' '){
                str.push_back(c);
            }
        }
        return traceback(str);
    }
    int traceback(deque<char> &str) {
        int num = 0;
        char last_operator = '+';
        vector<int> vstack;
        while(!str.empty()) {
            char c = str.front();
            str.pop_front();
            if(isdigit(c)){
                num = num * 10 +(c-'0');
            }else{
                switch(last_operator){
                    case '+':
                        vstack.push_back(num);break;
                    case '-':
                        vstack.push_back(-num);break;
                    case '*':{
                        int temp = vstack.back()*num;
                        vstack.pop_back();
                        vstack.push_back(temp);
                        break;}
                    case '/':{
                        int temp = vstack.back()/num;
                        vstack.pop_back();
                        vstack.push_back(temp);
                        break;}
                }
                num = 0;
                last_operator = c;
            }
        }
        switch(last_operator){
            case '+':
                vstack.push_back(num);break;
            case '-':
                vstack.push_back(-num);break;
            case '*':{
                int temp = vstack.back()*num;
                vstack.pop_back();
                vstack.push_back(temp);
                break;}
            case '/':{
                int temp = vstack.back()/num;
                vstack.pop_back();
                vstack.push_back(temp);
                break;}
        }
        return accumulate(vstack.begin(), vstack.end(),0);
    }
};