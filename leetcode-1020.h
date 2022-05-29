#include "utils.h"
// *飞地的数量，即统计岛屿单元数（总面积），不包括边缘
class Solution {
    int rows;
    int cols;
public:
    void dfs(vector<vector<int>>& grid,int i, int j){
        if(i<0||i>=rows||j<0||j>=cols){
            return;
        }
        if(grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    //-淹没四周的岛屿，然后计算剩余的‘1’的数量
    int numEnclaves(vector<vector<int>>& grid) {
        rows = (int)grid.size();
        cols = (int)grid[0].size();
        //-淹没四边岛屿
        for(int i = 0;i<rows;++i){
            dfs(grid,i,0);
            dfs(grid,i,cols-1);
        }
        for(int j = 0;j<cols;++j){
            dfs(grid,0,j);
            dfs(grid,rows-1,j);
        }
        int count = 0;
        for(int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j]==1){
                    ++count;
                }
            }
        }
        return count;
    }
};