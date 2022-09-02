#include "utils.h"
// *解数独
// *数字 1-9 在每一行只能出现一次。
// *数字 1-9 在每一列只能出现一次。
// *数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次.
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        traceback(board,0,0);
    }
    bool traceback(vector<vector<char>>& board,int i, int j){
        if(i == 9){
            return true;
        }
        if(j == 9){
            return traceback(board,i+1,0);
        }
        //-如果该位置已经预留了数字就回溯下一位
        if(board[i][j]!='.'){
            return traceback(board,i,j+1);
        }
        for(char c = '1';c<='9';++c){
            if(!isValid(board,i,j,c)){
                continue;
            }
            board[i][j] = c;
            if(traceback(board,i,j+1)){
                return true;
            }
            board[i][j] = '.';//-这行代码可以省略
        }
        return false;
    }
    //-判断在这个地方放数字是否合法
    bool isValid(vector<vector<char>>& board,int i, int j, char c){
        //-判断横向或者纵向或者3*3宫格有没有重复
        for(int index = 0;index < 9;++index){//-三宫格左上角坐标点
            if(board[i][index]==c||board[index][j]==c||board[(i/3)*3+index/3][(j/3)*3+index%3]==c){
                return false;
            }
        }
        return true;
    }
};