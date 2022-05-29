#include "utils.h"
// *无环图，求从0节点到n-1节点的所有可能路径
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //-因为是无环图,不需要visited数组
        vector<int> path = {0};
        traceback(graph,path,0);
        return res;
    }
    //-使用DFS遍历图
    void traceback(const vector<vector<int>>& graph,vector<int> &path,int node){
        //-走到n-1更新答案
        if(node == graph.size()-1){
            res.push_back(path);
        }
        //-遍历当前节点的所有邻接节点
        for(int neighbor : graph[node]){
            path.push_back(neighbor);
            traceback(graph,path,neighbor);
            path.pop_back();
        }
    }
};