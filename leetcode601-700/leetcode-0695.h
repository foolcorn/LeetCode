#include "utils.h"
// *不封闭岛屿的最大面积，即考虑边缘陆地
class Solution {
private :
    int rows;
    int cols;
public:
    //-思路，在dfs的同时记录岛屿面积
    int dfs(vector<vector<int>>& grid,int i, int j){
        if(i<0||i>=rows||j<0||j>=cols){
            return 0;
        }
        if(grid[i][j] == 0){
            return 0;
        }
        grid[i][j] = 0;
        return dfs(grid,i-1,j)+dfs(grid,i+1,j)+dfs(grid,i,j-1)+dfs(grid,i,j+1)+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = (int)grid.size();
        cols = (int)grid[0].size();
        int maxarea = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j] == 1){
                    int res = dfs(grid,i,j);
                    maxarea = max(maxarea,res);
                }
            }
        }
        return maxarea;
    }
};