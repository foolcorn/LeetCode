#include "utils.h"
// *将基因start转换为基因end，每次只能转一个碱基，且转换后的基因只有bank里的才是合法的，问最小转换次数
class Solution {
private:
    unordered_set<string> bankset;
    unordered_set<string> visited;
public:
    string change(const string &s,int i,char c){
        string temp = s;
        temp[i] = c;
        return temp;
    }
    string getLessChoice(const char &c){
        switch (c) {
            case 'A':
                return "CGT";
            case 'C':
                return "AGT";
            case 'G':
                return "ACT";
            case 'T':
                return "ACG";
        }
        return "ACGT";
    }
    //-思路：BFS
    int minMutation(string start, string end, vector<string>& bank) {
        for(auto& ele: bank){
            bankset.insert(ele);
        }
        deque<string> queue;
        queue.push_back(start);
        visited.insert(start);
        int count = 0;
        while(!queue.empty()){
            int size = (int)queue.size();
            for(int i = 0;i<size;++i){
                string temp = queue.front();
                queue.pop_front();
                if(temp == end){
                    return count;
                }
                for(int j = 0;j<8;++j){
                    string choice = getLessChoice(temp[j]);
                    for(char &c: choice){
                        string str = change(temp,j,c);
                        if(bankset.count(str)==0){
                            continue;
                        }
                        if(visited.count(str)>0){
                            continue;
                        }
                        visited.insert(str);
                        queue.push_back(str);
                    }
                }

            }
            ++count;
        }
        return -1;
    }
};