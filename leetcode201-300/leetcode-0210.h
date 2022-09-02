#include "utils.h"
// *课程表2，给定选修拓扑关系，返回一个拓扑排序后的序列
class Solution1 {
public:
    //-思路,建立每个节点的入度表,先把没有入度的节点插入答案。
    //-同时更新剩余节点的入度，把入度为0的节点继续插入答案。
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //-先根据拓扑关系建表
        vector<vector<int>> graph(numCourses,vector<int>());
        //-建立入度表
        vector<int> inlist(numCourses,0);
        for(auto& relation:prerequisites){
            graph[relation[1]].push_back(relation[0]);
            ++inlist[relation[0]];
        }
        //-最终答案
        vector<int> res;
        while(res.size()<numCourses){
            int startsize = (int)res.size();
            //-遍历入度表
            for(int i = 0;i<numCourses;++i){
                //-如果i节点已经在res中了
                if(inlist[i] < 0){
                    continue;
                    
                }
                //-如果入度为0了，加入到res中
                if(inlist[i]==0){
                    res.push_back(i);
                    //-更新当前的入度
                    --inlist[i];
                    //-同时更新剩余节点的入度
                    for(int &node:graph[i]){
                        --inlist[node];
                    }
                }
            }
            int endsize = (int)res.size();
            //-如果没有入度为0的节点了
            if (endsize == startsize){
                return {};
            }
        }
        return res;
    }
};

//-之前的解法BFS，效率高
class Solution {
public:
    //-思路,建立每个节点的入度表,先把没有入度的节点插入答案。
    //-同时更新剩余节点的入度，把入度为0的节点继续插入答案。
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //-先根据拓扑关系建表
        vector<vector<int>> graph(numCourses,vector<int>());
        //-建立入度表
        vector<int> inlist(numCourses,0);
        for(auto& relation:prerequisites){
            graph[relation[1]].push_back(relation[0]);
            ++inlist[relation[0]];
        }
        deque<int> nqueue;
        for(int i = 0;i<numCourses;++i){
            if(inlist[i] == 0){
                nqueue.push_back(i);
            }
        }
        //-最终答案
        vector<int> res;
        //-这里又个细节，如果是循环引用，一开始没有入度=0的node，那么queue为空不会进入循环
        //-同理，如果还没填完res，所有节点入度都!=0.那么queue也为空，不会继续循环，从而返回空
        while(!nqueue.empty()){
            int node = nqueue.front();
            nqueue.pop_front();
            res.push_back(node);
            if(res.size() == numCourses){
                return res;
            }
            for(int &neighbour:graph[node]){
                --inlist[neighbour];
                if(inlist[neighbour]==0){
                    nqueue.push_back(neighbour);
                }
            }
        }
        //-找不到最后返回{}
        return {};
    }
};