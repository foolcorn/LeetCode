#include "utils.h"
// *给定网格grid，计算不同岛屿的数量
class Solution {
    //-思路:递归的时候把路径返回，之后存入memo
private:
    unordered_set<string> memo;
public:
    void dfs(vector<vector<int>>& grid, string &path,string dst,int i, int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()){
            return;
        }
        if(grid[i][j]==0){
            return;
        }
        //-问题没有出现在这里
        path+=dst+",";
        grid[i][j] = 0;
        //-用上up，右right，下down，左left的字符来指示路径
        dfs(grid,path,"u",i-1,j);
        dfs(grid,path,"d",i+1,j);
        dfs(grid,path,"l",i,j-1);
        dfs(grid,path,"r",i,j+1);
        //-问题出现在这里，要把回溯的路径也加入到字符串中。
        path+=string("leave:")+dst+",";
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for(int j = 0;j< grid[0].size();++j){
                if(grid[i][j]==1){
                    string temp;
                    //-第一个字符串是什么字符不影响，c代表了center，中心位置
                    dfs(grid,temp,"c",i,j);
                    if(memo.count(temp)==0){
                        memo.insert(temp);
                    }
                }
            }
        }
        return (int)memo.size();
    }
};