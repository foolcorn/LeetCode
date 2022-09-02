#include "utils.h"
// *推多米诺
class Solution {
public:
    string pushDominoes(string dominoes) {
        deque<int> queue;
        for(int i = 0; i < dominoes.size();++i){
            if(dominoes[i]!='.'){
                queue.push_back(i);
            }
        }
        while(!queue.empty()) {
            int size = queue.size();
            vector<int> temp;
            for(int i = 0; i < size;++i){
                int index = queue.front();
                queue.pop_front();
                if(dominoes[index] == 'L'&&index>=1){
                    if(dominoes[index-1] == '.'){
                        dominoes[index-1] = 'l';
                    }else if(dominoes[index-1] == 'r'){
                        dominoes[index-1] = '.';
                    }else{
                        continue;
                    }
                    temp.push_back(index-1);
                }else if(dominoes[index] == 'R'&&index<dominoes.size()-1){
                    if(dominoes[index+1] == '.'){
                        dominoes[index+1] = 'r';
                    }else if(dominoes[index+1] == 'l'){
                        dominoes[index+1] = '.';
                    }else{
                        continue;
                    }
                    temp.push_back(index+1);
                }
            }
            for(int i = 0; i <temp.size();++i){
                if(dominoes[temp[i]]!='.'){
                    if(dominoes[temp[i]] == 'r'){
                        dominoes[temp[i]] = 'R';
                    }
                    if(dominoes[temp[i]] == 'l'){
                        dominoes[temp[i]] = 'L';
                    }
                    queue.push_back(temp[i]);
                }
            }
        }
        return dominoes;
    }
};