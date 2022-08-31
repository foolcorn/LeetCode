#include "utils.h"
// *单词搜索
class Solution {
private:
    vector<vector<bool>> visited;
public:
    bool traceback(vector<vector<char>>& board,int i,int j,string &word, int k){
        if(board[i][j] != word[k]){
            return false;
        }else if(k == word.size()-1){
            return true;
        }
        visited[i][j] = true;
        vector<vector<int>> direction ={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto &dir:direction){
            int newi = i+dir[0];
            int newj = j+dir[1];
            if(newi>=0&&newi<board.size()&&newj>=0&&newj<board[0].size()){
                if(!visited[newi][newj]){
                    if(traceback(board,newi,newj,word,k+1)){
                        return true;
                    }
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        visited.resize(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 0;i<board.size();++i){
            for(int j = 0; j <board[0].size();++j){
                if(traceback(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
