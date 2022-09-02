#include "utils.h"
// *三角形的最小路径和
class Solution {
private:
    vector<vector<int>>memo;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        memo.resize(triangle.size(),vector<int>(triangle.back().size(),-1));
        int res = INT_MAX;
        for(int i = 0; i < triangle.back().size(); i++){
            res = min(res,traceback(triangle,triangle.size()-1,i));
        }
        return res;
    }
    int traceback(vector<vector<int>>& triangle, int row,int col){
        if(row == 0){
            return triangle[0][0];
        }
        if(col<0||col>=triangle[row].size()){
            return INT_MAX;
        }
        if(memo[row][col]!=-1){
            return memo[row][col];
        }
        int res1 = traceback(triangle, row-1, col-1);
        int res2 = traceback(triangle, row-1, col);
        memo[row][col] = min(res1,res2)+triangle[row][col];
        return memo[row][col];
    }
};