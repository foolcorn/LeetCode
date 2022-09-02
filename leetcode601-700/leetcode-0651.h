#include "utils.h"
// *四键键盘：只有四种操作，
// *按A键，在屏幕上打印一个 'A'
// *Ctrl-A：选中整个屏幕。
// *Ctrl-C：复制选中区域到缓冲区。
// *Ctrl-V：将缓冲区内容输出到上次输入的结束位置，并显示在屏幕上。
// *问按n次键后，屏幕最多能显示的A数量
class Solution {
public:
    //-思路：优化dp，之前用了四个状态，其实转变dp数组的意义会变得更简单，dp[i]为操作i次的时候的最大A数
    //-为什么可以这样，因为想要获得最多A，到第i步只可能是按A，或者ctrlV操作
    int maxA(int n) {
        vector<int> dp(n+1,0);//-默认初始化为0
        for(int i  = 1;i<=n;++i){
            //-如果第i步是选择按A键
            dp[i] = dp[i-1]+1;
            for(int j = 2;j<i;++j){
                //-如果第i步选择ctrlv，由于不清楚是从什么时候开始ctrlA+ctrlC,则需要遍历<i的所有情况，留两步空操作给ctrlA+ctrlC
                dp[i] = max(dp[i],dp[j-2]*(i-j+1));
            }
        }
        return dp[n];
    }
};