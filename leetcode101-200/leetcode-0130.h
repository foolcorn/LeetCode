#include "utils.h"
// *相当于把所有封闭岛屿，不包括边缘，变成海水
class Solution {
    int rows = 0;
    int cols = 0;
public:
    void solve(vector<vector<char>>& board) {
        rows = (int)board.size();
        cols = (int)board[0].size();
        //-先把边缘的0变成另一个字符#
        for(int i = 0;i<rows;++i){
            DFS(board,i,0);
            DFS(board,i,cols-1);
        }
        for(int j = 0;j<cols;++j){
            DFS(board,0,j);
            DFS(board,rows-1,j);
        }
        for(int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j) {
                //-将不是边缘的岛屿变成海水
                if(board[i][j] == 'O'){board[i][j] = 'X';}
                //-将临时的标志#变回岛屿
                if(board[i][j] == '#'){board[i][j] = 'O';}
            }
        }

    }
    void DFS(vector<vector<char>>& board,int i, int j){
        if(i<0||i>=rows||j<0||j>=cols){
            return;
        }
        if(board[i][j] != 'O'){
            return;
        }
        board[i][j] = '#';
        DFS(board,i-1,j);
        DFS(board,i+1,j);
        DFS(board,i,j-1);
        DFS(board,i,j+1);
    }
};