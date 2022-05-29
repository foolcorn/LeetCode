#include "utils.h"
// *给定n代表有几对括号，生成所有合法括号串
class Solution {
    vector<string> brackets;
    vector<bool> used;
    vector<string> res;
    //-思路:抽象成可重复元素不重复取的排列问题，只是在排列的基础上，需要满足左括号和右括号的合法性
    //-使用leftnum和rightnum指示之前子串的左括号数和右括号数，才判断遇到的右括号能不能加
public:
    vector<string> generateParenthesis(int n) {
        for(int i =0; i<n; ++i){
            brackets.emplace_back("(");
            brackets.emplace_back(")");
        }
        used = vector<bool>(n*2,false);
        sort(brackets.begin(),brackets.end());
        string temp;
        traceback(temp,0,0);
        return res;
    }
    void traceback(string &temp, int leftnum, int rightnum){
        if(temp.size() == brackets.size()){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<brackets.size();++i){
            if(i>0 && brackets[i]==brackets[i-1]&&!used[i-1]){
                continue;
            }
            if(used[i]){
                continue;
            }
            //-左括号只要遇到可以加
            if(brackets[i]=="("){
                temp+=brackets[i];
                used[i] = true;
                traceback(temp, leftnum+1, rightnum);
                used[i] = false;
                temp.pop_back();
            }else{
                //-遇到右括号要判断之前左括号够不够才能加
                if(leftnum<=rightnum){
                    continue;
                }else {
                    temp += brackets[i];
                    used[i] = true;
                    traceback(temp, leftnum, rightnum+1);
                    used[i] = false;
                    temp.pop_back();
                }
            }
        }
    }
};