#include "utils.h"
// *给定字符串s，返回其字典序最小的子序列（无序）
class Solution {
public:
    //-思路:使用单调栈的思维，从头开始遍历字符，如果发现当前字符不在栈中，且比栈头元素的字典序小，
    //-而且后面还有栈头元素，就把栈头元素pop掉
    string smallestSubsequence(string s) {
        //-记录栈里是否有某个元素
        unordered_set<char> instack;
        //-记录后面一个字符有多少插入机会
        unordered_map<char,int>count;
        for(int i = 0; i < s.size(); ++i){
            ++count[s[i]];
        }
        //-用vector代替栈
        vector<char> vstack;
        for (int i = 0; i < s.size(); ++i) {
            //如果栈里有元素存在就跳过
            if(instack.count(s[i])>0){
                --count[s[i]];
                continue;
            }
            //-如果新元素小于栈顶元素且后面还有替补就pop
            while(!vstack.empty()&&vstack.back()>s[i]&&count[vstack.back()]>0){
                instack.erase(vstack.back());
                vstack.pop_back();
            }
            //-插入新元素
            vstack.push_back(s[i]);
            instack.insert(s[i]);
            --count[vstack.back()];
        }
        string res(vstack.begin(), vstack.end());
        return res;
    }
};