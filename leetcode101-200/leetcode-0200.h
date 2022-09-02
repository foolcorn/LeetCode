#include "utils.h"
// *计算岛屿的数量，包括边缘的陆地也算岛屿
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()){
            return;
        }
        if(grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();
        int count = 0;
        for(int i = 0;i<rows;++i){
            for (int j = 0; j < cols; ++j) {
                if(grid[i][j] == '1'){
                    ++count;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};