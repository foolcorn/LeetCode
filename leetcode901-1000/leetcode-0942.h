#include "utils.h"
// *s为字符为‘I’和‘D’组成的序列，可以出现0次或者多次，将字符串译码成可能的数字序列，
// *I代表后一个数>前一个数，D代表后一个数<前一个数，译码出的数字在0-n的范围，和字符串长度一致
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int up = 0;
        int down = 0;
        int cur = 0;
        //-从0开始构造序列，最后整体向上平移即可。
        vector<int> res = {0};
        for(auto&c:s){
            if(c=='I'){
                ++up;
                res.push_back(up);
            }else{
                --down;
                res.push_back(down);
            }
        }
        for(auto& ele:res){
            ele-=down;
        }
        return res;
    }
};