#include "utils.h"
// *从左上角到右下角的最短路径和，每次只能向下或者向右移动
//-思路：从终点回溯，动态规划做选择
class Solution {
private:
    vector<vector<int>> memo;
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();
        memo = vector<vector<int>>(rows,vector<int>(cols,-1));
        return traceback(grid,rows-1,cols-1);
    }
    //-从起始点走到i，j的最短路径长度
    int traceback(vector<vector<int>>& grid, int i,int j){
        if(i < 0 || j<0){
            return INT_MAX;
        }
        if(i==0&&j==0){
            return grid[0][0];
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        memo[i][j] = min(traceback(grid,i-1,j),traceback(grid,i,j-1))+grid[i][j];
        return memo[i][j];
    }
};