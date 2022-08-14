#include "utils.h"
// *最长公共前缀
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int col = 0; col<200;++col){
            char temp = strs[0][col];
            for(int i =0;i<strs.size();++i){
                if(col>=strs[i].size()){
                    return strs[0].substr(0,col);
                }
                if(strs[i][col]!=temp){
                    return strs[0].substr(0,col);
                }
            }
        }
        return strs[0];
    }
};