#include "utils.h"
// *判断二分图
class Solution {
private:
    //-保存每个节点的颜色
    vector<bool> color;
    //-保存走过的路径
    vector<bool> visited;
    //-全局标志位
    bool sign = true;
public:
    //-思路使用着色原理，利用DFS给每个点赋予颜色
    bool isBipartite(vector<vector<int>>& graph) {
        color = vector<bool>(graph.size(),false);
        visited = vector<bool>(graph.size(),false);
        for(int i = 0;i<graph.size();++i){
            if(!visited[i]){
                traceback(graph, i);
            }
        }
        return sign;
    }
    void traceback(vector<vector<int>>& graph, int node){
        if(!sign){
            return;
        }
        //-为什么这里不用判断如果visited就return？因为只有！visited才会traceback下一个
        //-标志已经走过
        visited[node] = true;
        //-遍历每一个相邻节点
        for(int neighbour:graph[node]){
            //-如果该节点没有visited,就给它上色
            if(!visited[neighbour]){
                color[neighbour] = !color[node];
                //-遍历下一个node,
                traceback(graph,neighbour);
            }else{
                //-如果有visited，试探是否颜色不同
                sign = color[neighbour]!=color[node];
                if(!sign){
                    return;
                }
            }
        }
    }
};
