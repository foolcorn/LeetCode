#include "utils.h"
// *约瑟夫环：n个人，1~n,围成一圈，从1开始（包括1）往右数第k个人出局，之后从k的下个人开始继续数第k个人出局，
// *不断循环直到最后一个人为赢家，返回赢家
//-思路使用队列，每次pop队首，然后再push进队尾，直到第k个，真的pop掉。直到队列只剩一个人
class Solution {
    int total;
    vector<bool> used;
//-我这个是旧方法，没用队列，用used数组标识谁出局了，没有啥参考价值，而且效率低。
public:
    int upperIndex(int index){
        for(int i = 0;i<total;++i){
            ++index;
            index = index == total ?0:index;
            if(!used[index]){
                return index;
            }
        }
        return -1;
    }
    int findTheWinner(int n, int k) {
        used = vector<bool>(n, false);
        total = n;
        int index = 0;
        int lastIndex = 0;
        while(index!=-1){
            for(int i =0;i<k-1;++i){
                index = upperIndex(index);
            }
            used[index] = true;
            lastIndex = index;
            index = upperIndex(index);
        }
        return lastIndex+1;
    }
};