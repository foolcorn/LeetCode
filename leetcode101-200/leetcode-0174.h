#include "utils.h"
// *地下城游戏，从左上角走到右下角，dungeon[i]>0加血，dungeop[i]<0掉血，dungeop[i]==0无事发生。
// *问初始最低血量
class Solution {
    int rows;
    int cols;
    vector<vector<int>> memo;
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        rows = (int)dungeon.size()-1;
        cols = (int)dungeon[0].size()-1;
        memo = vector<vector<int>>(rows+1, vector<int>(cols+1,-1));
        return traceback(dungeon,0,0);
    }
    //-从i,j位置走到右下角最少需要的血量
    int traceback(vector<vector<int>>& dungeon,int i, int j){
        if(i>rows||j>cols){
            return INT_MAX;
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        if(i == rows&&j == cols){
            //-避免落地成盒
            memo[i][j] = dungeon[i][j]<0? 1-dungeon[i][j] : 1;
            return memo[i][j];//-至少有一滴血才能前进
        }
        //-每个ij的血量由自己下方的traceback和右边的traceback来决定
        int minblood = min(traceback(dungeon,i+1,j),traceback(dungeon,i,j+1));
        //-无论dungeon[i][j]正负，先看成是到达此处会获得的血量加成
        if(minblood>dungeon[i][j]){//-当最小血量minblood大于dungeon[i][j]，说明我们为了让走到下个格子的时候满足minblood血量，需要算出一个初始血量x
            memo[i][j] = minblood-dungeon[i][j];//-相当于我们需要让x+dungeon[i][j] == min blood;
        }else{//-如果dungeon[i][j]>=minblood，说明，只要一滴血(x==1)到达此处
            memo[i][j] = 1;//-则x+dungeon[i][j]必然>min blood也满足条件
        }
        return memo[i][j];
    }
};