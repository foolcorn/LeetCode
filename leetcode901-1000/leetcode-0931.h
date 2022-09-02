#include "utils.h"
// *下降路径最小和： matrix（n*n）记录了路径value，
// *从第一行任意元素开始，可以选择下一行的左中右三个位置进行移动，18%
class Solution {
    vector<vector<int>> matrix;
    vector<vector<int>> memo;
    int size;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        size = matrix.size();
        memo = vector<vector<int>>(size,vector<int>(size,-101));
        int minsum = INT_MAX;
        for(int i = 0;i<size;++i){
            //-由于起始点不确定,所以对于最后一行的每一列都要递归一次，求最小值
            minsum = min(minsum,traceback(size-1,i));
        }
        return minsum;
    }
    //-dp是二维数组,代表了走到当前行列时的最小路径和
    int traceback(int row, int col){
        if(col<0||col>=size){
            return INT_MAX;
        }
        if(row == 0){
            return matrix[0][col];
        }
        if(memo[row][col]!=-101){
            return memo[row][col];
        }
        //-做选择
        int sum1 = traceback(row-1,col-1);
        int sum2 = traceback(row-1,col);
        int sum3 = traceback(row-1,col+1);
        memo[row][col] = matrix[row][col] + min(sum1,min(sum2,sum3));
        return memo[row][col];
    }
};