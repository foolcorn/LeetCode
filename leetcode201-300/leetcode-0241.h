#include "utils.h"
// *给表达式加括号，可以得到多少种不同的运算结果，运算符有+-*三种
//-思路：使用分治思想来加括号即可,有点类似之前构造BST的意思了
class Solution {
public:
    //-分治递归
    vector<int> traceback(string expression){
        //-字符串小于2是无法构成表达式的,只可能是0-99的数字
        if(expression.size() <=2){
            return {stoi(expression)};
        }
        vector<int> res;
        //-串长度如果>=3,必有一个运算符，遍历找到
        for(int i = 0;i<expression.size();++i){
            if(expression[i] == '+'){
                vector<int> left = traceback(expression.substr(0,i));
                vector<int> right = traceback(expression.substr(i+1));
                for(auto & le:left){
                    for(auto & re:right){
                        res.push_back(le+re);
                    }
                }
            }
            if(expression[i] == '-'){
                vector<int> left = traceback(expression.substr(0,i));
                vector<int> right = traceback(expression.substr(i+1));
                for(auto & le:left){
                    for(auto & re:right){
                        res.push_back(le-re);
                    }
                }
            }
            if(expression[i] == '*'){
                vector<int> left = traceback(expression.substr(0,i));
                vector<int> right = traceback(expression.substr(i+1));
                for(auto & le:left){
                    for(auto & re:right){
                        res.push_back(le*re);
                    }
                }
            }
        }
        return res;
    }

    vector<int> diffWaysToCompute(string expression) {
        return traceback(expression);
    }
};

