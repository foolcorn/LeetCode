#include "utils.h"
// *最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        //-由于模式串可能有重复字符，用map不好判断是不是所有字符都包含了，所以使用valid作为是否全部匹配的条件
        //-只有当map中重复字符的数量达到target中该字符的数量，valid才会++，直到valid==target.size为止
        int left = 0,right = 0;
        int valid = 0;
        int len = INT_MAX;int index = 0;
        unordered_map<char,int> window,target;
        for(char &c:t){
            ++target[c];
        }
        string res(s);
        while(right<s.size()){
            char c = s[right];
            if(target.count(c)>0){
                ++window[c];
                if(window[c]==target[c]){
                    ++valid;
                }
            }
            ++right;
            while(valid == target.size()){
                char d = s[left];
                //-删掉left前先保存结果
                if(len>right-left){
                    len = right-left;
                    index = left;
                }
                ++left;
                //-先判断该字符是否存在map里
                if(window.count(d)>0){
                    //-如果是从刚刚匹配的状态删除,--valid
                    if(window[d]==target[d]){
                        --valid;
                    }
                    --window[d];
                }
            }
        }
        // cout<<s.substr(left-1,len);
        return len == INT_MAX?"":s.substr(index,len);
    }
};