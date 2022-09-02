#include "utils.h"
// *给定不喜欢的拓扑关系，把n个人分成两组，如果互不喜欢的两个人，不应该分到同一组
class Solution {
    //-color数组维护颜色
    vector<bool> color;
    //-visited数组维护是否有上过颜色
    vector<bool> visited;
    //-最终答案标志位
    bool sign = true;
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //-利用着色原理,把dislikes关系看成是边,该边的两头必须是不同颜色
        // -利用dislikes建图，注意，dislike是无向图，所以建图要对称！
        vector<vector<int>>graph(n+1,vector<int>());
        for(auto edge:dislikes){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        //-初始化两个数组
        color = vector<bool>(n+1,false);
        visited = vector<bool>(n+1,false);
        //-以每个节点开头都遍历一遍
        for (int i = 1; i <= n; ++i) {
            if(!visited[i]){
                traceback(graph,i);
            }
        }
        return sign;
    }
    void traceback(vector<vector<int>>& graph,int node){
        //-已经不是二分图了,不用浪费时间
        if(!sign){
            return;
        }
        visited[node] = true;
        for(auto neighbor:graph[node]){
            //-如果上过颜色,判断是否不等
            if(visited[neighbor]){
                sign = color[neighbor]!=color[node];
                if(!sign){
                    return;
                }
            }else{
                //-没上过颜色就给其不同的颜色,并进入下一个节点的DFS
                color[neighbor] = !color[node];
                traceback(graph, neighbor);
            }
        }
    }
};
