#include "utils.h"
// *正则表达式，p是正则表达式（包括*和.）判断s是否匹配p
// *（‘.’代表匹配任意单个字符，‘*’代表匹配0个或多个前面那个字符）
class Solution {
private:
    unordered_map<string,bool> memo;
public:
    bool isMatch(string s, string p) {
        return traceback(s,p,0,0);
    }
    bool traceback(string s, string p,int i, int j){
        int m = s.size();
        int n = p.size();
        if(j==n){
            return i == m;
        }
        //-如果s到达终点，但是p还没匹配完，检查剩余的p是否是成对的‘ele*’
        if(i==m){
            bool sign = true;
            for(;j<n;j+=2){
                if(j+1>=n || p[j+1] != '*'){
                    sign = false;
                }
            }
            return sign;
        }
        string str = to_string(i)+"_"+to_string(j);
        if(memo.count(str)>0){return memo[str];}
        bool res = false;
        //-如果字符相等,或者p此时为'.'可以匹配任意字符
        if(p[j] == s[i]||p[j] == '.'){
            //-如果该字符后面有'*',可能匹配0次(i不动,j+2)或者匹配一次或者多次(i+1,j不动)
            if(j+1<n && p[j+1] == '*'){
                res = traceback(s,p,i,j+2)||traceback(s,p,i+1,j);
            }
            //-没有*就正常匹配
            else{
                res = traceback(s,p,i+1,j+1);
            }
        }
        //-当前字符不相等,但是如果p是'.*'或者'ele*'的形式,则'*'可以匹配0次直接跳过,如果不符合这种情况,则匹配失败
        else{
            if(j+1<n && p[j+1] == '*'){
                //-直接跳过'ele*'
                res = traceback(s,p,i,j+2);
            } else{
                res = false;
            }
        }
        memo[str] = res;
        return res;
    }
};