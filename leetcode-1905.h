#include "utils.h"
// *给定两个岛屿，计算grid2相对于grid1的子岛屿的数量
class Solution {
private:
    int rows;
    int cols;
public:
    void dfs(vector<vector<int>>& grid,int i ,int j){
        if(i<0||i>=rows||j<0||j>=cols){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        grid[i][j] = 0;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        rows = (int)grid1.size();
        cols = (int)grid1[0].size();
        //-淹掉grid2中不是子岛屿的岛
        for(int i =0;i<rows;++i){
            for (int j = 0; j < cols; ++j) {
                //-如果grid2是陆地而grid1是海水
                if(grid2[i][j]==1&&grid1[i][j] == 0){
                    dfs(grid2,i,j);
                }
            }
        }
        int count = 0;
        for(int i =0;i<rows;++i){
            for (int j = 0; j < cols; ++j) {
                if(grid2[i][j]==1){
                    ++count;
                    dfs(grid2,i,j);
                }
            }
        }
        return count;
    }
};