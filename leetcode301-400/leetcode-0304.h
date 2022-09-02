
-#include "utils.h"
// * 返回区间内二维数组子数组的和
class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 0|| col == 0){return;}
        for(int i = 0;i<=row; ++i){
            sum.emplace_back(col+1,0);
        }
        for(int i = 0; i <row; ++i){
            for(int j = 0; j<col; ++j){
                sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] + matrix[i][j] -sum[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];
    }
};