#include "utils.h"
// *字符串是否包含另一个字符串的排列
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0,right = 0;
        unordered_map<char,int>window,target;
        int valid = 0; int length = 0;
        for(auto ele: s1){
            ++target[ele];
        }
        while(right<s2.size()){
            char c = s2[right];
            ++right;++length;
            if(target.count(c)>0){
                ++window[c];
                if(window[c]==target[c]){
                    ++valid;
                }
            }
            while (length>s1.size()){
                char d = s2[left];
                ++left;--length;
                if(window.count(d)>0){
                    if(window[d]==target[d]){
                        --valid;
                    }
                    --window[d];
                }
            }
            if(valid == target.size()){
                return true;
            }
        }

        return false;
    }
};