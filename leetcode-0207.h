#include "utils.h"
// *课程表1：给定拓扑关系prerequisites，代表先修课程和后修课程的关系，判断是否能完成学习
class Solution {
private:
    vector<bool> visited;
    bool sign = true;
public:
    //-只要该拓扑图无环即可完成学习，有环则不行
    //-DFS遍历图，用visited记录走过的路径，如果遍历neighbour的时候发现有环就return false
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //-先根据拓扑关系建立图像。
        vector<vector<int>>graph(numCourses,vector<int>());
        for(auto courses:prerequisites){
            graph[courses[1]].push_back(courses[0]);
        }
        //-visited数组
        visited = vector<bool>(numCourses,false);
        //-相当于一个简化版的路径，只记录路径中是否存在，而不在乎顺序
        unordered_set<int> path;
        //-对每个节点都遍历一遍
        for(int i = 0;i<numCourses;++i){
            traceback(graph,path,i);
        }
        return sign;
    }
    void traceback(const vector<vector<int>>& graph, unordered_set<int> &path, int node){
        if(!sign){
            return;
        }
        if(path.count(node)>0){
            //-这个path的意义在于，临时某条路径中，如果有环
            sign = false;
            return;
        }
        if(visited[node]){
            //-可以想象成这个visited的意义在于二叉树的叶子结点，如果遍历到头了就return
            return;
        }
        visited[node] = true;
        path.insert(node);
        for(auto& neighbour:graph[node]){
            traceback(graph,path,neighbour);
        }
        path.erase(node);
    }
};