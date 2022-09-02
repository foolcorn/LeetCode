#include "utils.h"
// *旋转二维数组
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = (int)matrix.size();
        int cols = rows;
        //-按副对角线翻转
        for(int i = 0;i<rows; ++i){
            for(int j = i+1;j<cols;++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //-左右对称翻转
        for(int j = 0;j<cols/2;++j){
            for(int i = 0;i<rows;++i){
                swap(matrix[i][j],matrix[i][cols-j-1]);
            }
        }
    }
};