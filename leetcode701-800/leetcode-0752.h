#include "utils.h"
// *打开轮盘锁
class Solution {
public:
    //-向上转
    string turnUp(string s, int index){
        char &c = s[index];
        c = c == '9'?'0':c+1;
        return s;
    }
    //-向下转
    string turnDown(string s, int index){
        char &c = s[index];
        c = c == '0'?'9':c-1;
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendsSet;//-记录死锁情况
        for(auto &ele:deadends){
            deadendsSet.insert(ele);
        }
        unordered_set<string> visited;//-使用visited记录走过的路径
        deque<string> queue;
        queue.emplace_back("0000");//-初始队列
        visited.insert("0000");//-加入visited
        int count = 0;
        while(!queue.empty()) {
            int size = (int)queue.size();
            for(int i = 0;i<size;++i){
                string temp = queue.front();
                queue.pop_front();
                //-如果是死锁就跳过
                if(deadendsSet.count(temp)){
                    continue;
                }
                //-如果是目标，BFS第一个找到的目标就是结果
                if(temp == target){
                    return count;
                }
                //-一共八种情况，没有在visited的就加入
                for(int j = 0;j<temp.size();++j){
                    string up = turnUp(temp,j);
                    if(visited.count(up)==0){
                        queue.push_back(up);
                        visited.insert(up);
                    }
                    string down = turnDown(temp,j);
                    if(visited.count(down)==0){
                        queue.push_back(down);
                        visited.insert(down);
                    }
                }
            }
            ++count;
        }
        return -1;
    }
};