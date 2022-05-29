#include "utils.h"
// *滑动谜题，类似华容道，把打乱的二维数组恢复成[[1,2,3][4,5,0]]
// *返回最小的移动次数
class Solution {
public:
    string swapstr(string s,int i, int j){
        swap(s[i],s[j]);
        return s;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        //-位置映射表，将二维数组压缩成一维后，记录某个索引和其相邻的索引号
        vector<vector<int>> mmap = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string target = "123450";
        string start;
        //-初始化状态
        for(auto & row : board) {
            for(auto & ele : row){
                start += to_string(ele);
            }
        }
        //-状态队列
        deque<string> queue = {start};
        //-记录路径
        unordered_set<string> visited = {start};
        //-计数
        int count =0;
        //-开始循环
        while(!queue.empty()){
            int size = (int)queue.size();
            for(int i = 0;i<size;++i){
                string status = queue.front();
                queue.pop_front();
                if(status == target){
                    return count;
                }
                //-找到一个状态有几种转移可能
                int pos = (int)status.find('0');
                for(int index:mmap[pos]){
                    string new_status = swapstr(status,pos,index);
                    if(visited.count(new_status)==0){
                        visited.insert(new_status);
                        queue.push_back(new_status);
                    }
                }
            }
            ++count;
        }
        return -1;
    }
};
