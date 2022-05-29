#include "utils.h"
// *封闭岛屿的数量，不包括边缘的陆地
class Solution {
private:
    int rows;
    int cols;
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i<0||i>=rows||j < 0 || j >= cols){
            return;
        }
        if(grid[i][j] == 1){
            return;
        }
        grid[i][j] = 1;
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        rows = (int)grid.size();
        cols = (int)grid[0].size();
        //-淹没四边的岛屿
        for(int i = 0; i < rows; ++i) {
            dfs(grid,i,0);
            dfs(grid, i, cols-1);
        }
        for (int j = 0; j < cols; ++j) {
            dfs(grid,0,j);
            dfs(grid, rows-1, j);
        }
        int count = 0;
        //-遍历即可
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j] == 0){
                    ++count;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};