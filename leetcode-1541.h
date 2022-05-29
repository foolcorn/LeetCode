#include "utils.h"
// *插入左右括号，平衡括号串使其合法，假如一个左括号匹配两个右括号，问最少插入次数
class Solution {
public:
    int minInsertions(string s) {
        //-在类栈遍历的时候，指示临时需要的右括号的数量。
        int needright = 0;
        //-记录最终插入次数
        int insertCount = 0;
        for(int i = 0;i<s.size();++i) {
            char c = s[i];
            if(c == '('){
                //-别忘了保证括号的合法性，
                //-如果右括号是单数，就说明遇到新的左括号之前，左括号和右括号是不匹配的，那就需要插入一个右括号，同时减掉这个单数的需求
                if(needright % 2 == 1){
                    --needright;
                    ++insertCount;
                }
                //-遇到新左括号,对右括号的临时需求needright+2
                needright+=2;
            }else{
                //-遇到一个右括号，就减掉一个右括号的需求，needright-1
                --needright;
                //-如果还没遇到一个左括号就遇到右扩号，插入一个左括号，同时还需要一个额外的右括号
                if(needright == -1){
                    needright = 1;
                    ++insertCount;
                }
            }
        }
        //-遍历完所有元素,insertCount是目前插入的括号数,而needright则包含了还没有匹配的右括号数量
        return insertCount+needright;
    }
};