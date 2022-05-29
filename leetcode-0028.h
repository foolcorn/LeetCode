#include "utils.h"
// * 字符串匹配（KMP算法）
class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1 = (int)haystack.size();
        int length2 = (int)needle.size();
        //-状态机
        vector<vector<int>> status(length2,vector<int>(256,0));
        //-初始状态转移
        status[0][needle[0]] = 1;
        //-上一个状态
        int last_status = 0;
        //-遍历状态机
        for(int i = 1;i<length2;++i){
            //-对于子串的每一种状态，遇到不是匹配的下一个字符，就退回到上一个状态去匹配,
            //-比如状态4要匹配‘a’才会到状态5，但是匹配的是‘b’，所以找一下以前的状态来匹配试一下。
            //-在这个过程中，可能会有以前的某个状态2，遇到‘b’是匹配的，会转移到状态3
            //-说明在状态4匹配‘b’==状态2匹配‘b’，那就可以从状态2继续往下匹配。
            //-只要不退回到初始状态0，就是赚的，这就是kmp
            for(int c = 0;c<256;++c){
                status[i][c] = status[last_status][c];
            }
            //-如果当前状态的成功匹配则可以转移到下一个状态
            status[i][needle[i]] = i+1;
            //-更新上一个状态
            last_status = status[last_status][needle[i]];
        }
        //-用状态机进行匹配
        int j = 0;
        for(int i = 0;i<length1;++i){
            j = status[j][i];
            if(j == length2){
                return i-length2+1;
            }
        }
        return -1;
    }
};