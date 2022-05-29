#include "utils.h"
// *N皇后，新的皇后不能和之前的皇后在同一行，同一列，同一对角线
class Solution {
private:
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        //-构造棋盘
        vector<string>temp(n,string(n,'.'));
        traceback(temp,0);
        return res;
    }
    //-检查同一列
    bool checkTop(const vector<string>&temp, int row, int col){
        bool sign = true;
        for(int i = 0;i<row;++i){
            if(temp[i][col] == 'Q'){
                sign = false;
                break;
            }
        }
        return sign;
    }
    //-检查左上对角线
    bool checkTopleft(const vector<string>&temp, int row, int col){
        bool sign = true;
        while(row>=0&&col>=0){
            if(temp[row][col] == 'Q'){
                sign = false;
                break;
            }
            --row;
            --col;
        }
        return sign;
    }
    //-检查右上对角线
    bool checkTopright(const vector<string>&temp, int row, int col){
        int size = temp[0].size();
        bool sign = true;
        while(row>=0&&col<size){
            if(temp[row][col] == 'Q'){
                sign = false;
                break;
            }
            --row;
            ++col;
        }
        return sign;
    }
    void traceback(vector<string>&temp, int row){
        //-如果插入完最后一行，row==size,更新答案
        if(row==temp.size()){
            res.push_back(temp);
            return;
        }
        //-对于当前行的每一列都尝试放皇后
        for(int col = 0;col<temp[row].size();++col){
            if(checkTop(temp,row,col)&&checkTopleft(temp,row-1,col-1)&&checkTopright(temp,row-1,col+1)){
                temp[row][col] = 'Q';
                traceback(temp, row+1);
                temp[row][col] = '.';
            }
        }
    }
};