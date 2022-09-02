#include "utils.h"
// *给定字符串去除重复的字母，且保证字典序最小
class Solution {
public:
    //-思路:使用单调栈的思维，从头开始遍历字符，如果发现当前字符不在栈中，且比栈头元素的字典序小，
    //-而且后面还有栈头元素，就把栈头元素pop掉
    string removeDuplicateLetters(string s) {
        //-构建入栈unordered_set，判断当前元素是否已经在栈中了
        unordered_set<char> instack;
        //-用map存每个字符的数量，判断后面还有没有该元素
        unordered_map<char,int> count;
public:
    string removeDuplicateLetters(string s) {
        //-构建入栈unordered_set
        unordered_set<char> instack;
        //-用map存每个字符的数量
        unordered_map<char,int> count;
        for (int i = 0; i < s.size(); ++i) {
            ++count[s[i]];
        }
        //-用vector模拟一个栈
        vector<char> cstack;
        //-入栈
        for(int i = 0; i < s.size(); ++i){
            //-如果元素在栈中就忽略，并且更新map，减少该字符的可用数量
            if(instack.count(s[i])>0){
                --count[s[i]];
                continue;
            }
            while(!cstack.empty()&&cstack.back()>s[i]&&count[cstack.back()]>0){
                instack.erase(cstack.back());
                cstack.pop_back();
            }
            instack.insert(s[i]);
            cstack.push_back(s[i]);
            --count[s[i]];
        }
        string res(cstack.begin(),cstack.end());
        return res;
    }
};