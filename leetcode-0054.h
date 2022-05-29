#include "utils.h"
// *螺旋遍历二维数组
class Solution {
public:
    //-思路，框定上下左右边界，每次收缩，直到无法收缩，遍历停止
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int down = (int)matrix.size();
        int left = 0;
        int right = (int)matrix[0].size();
        char direction = 'r';
        vector<int> res;
        int i = 0;
        int j = 0;
        while(true){
            switch(direction){
                //-向右走
                case 'r':
                    if(j >= right){
                        return res;
                    }
                    while(j<right){
                        res.push_back(matrix[i][j]);
                        ++j;
                    }
                    //-收缩上边界
                    ++top;
                    //-指向下个起点
                    --j;
                    ++i;
                    //-改变方向
                    direction = 'd';
                    break;
                case 'd':
                    if(i >= down){
                        return res;
                    }
                    while(i<down){
                        res.push_back(matrix[i][j]);
                        ++i;
                    }
                    //-收缩右边界
                    --right;
                    //-指向下个起点
                    --i;
                    --j;
                    //-改变方向
                    direction = 'l';
                    break;
                case 'l':
                    if(j < left){
                        return res;
                    }
                    while(j>=left){
                        res.push_back(matrix[i][j]);
                        --j;
                    }
                    //-收缩下边界
                    --down;
                    --i;
                    ++j;
                    direction = 'u';
                    break;
                case 'u':
                    if(i < top){
                        return res;
                    }
                    while(i>=top){
                        res.push_back(matrix[i][j]);
                        --i;
                    }
                    //-收缩左边界
                    ++left;
                    ++i;
                    ++j;
                    direction = 'r';
                    break;
            }
        }
    }
};