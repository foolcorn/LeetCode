#include "utils.h"
// *Nim游戏，给定n个石子，每次每人拿1~3个石子，谁最后拿走所有石子就能赢，你作为先手判断是否能赢
class Solution {
public:
    //-思路：谁拿的时候，如果是4的倍数必输，所以判断一下开局是不是4，如果是的话直接认输，反之，如果开局不是4的倍数，
    //-我可以拿走1~3颗石子，让对手面对4的倍数，则我必赢
    bool canWinNim(int n) {
        if(n%4==0){
            return false;
        }
        return true;
    }
};