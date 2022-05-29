#include "utils.h"
// *给定一个points数组，每个point是一个二维坐标，每两个点连接费用为两点的曼哈顿距离
// *曼哈顿距离：|xi - xj| + |yi - yj|，求连接所有节点的最小费用
class UF{
private:
    vector<int> parent;
    int count;
public:
    explicit UF(int n):count(n){
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }
    }
    void connect(int a,int b){
        int root1 = find(a);
        int root2 = find(b);
        if (root1 == root2) {
            return;
        }
        parent[root2] = root1;
        --count;
    }
    bool if_connected(int a, int b){
        return find(a) == find(b);
    }
    int find(int node){
        if(parent[node]!=node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};
class Edge{
public :
    int i;
    int j;
    int value;
    Edge(int x,int y, int val):i(x),j(y),value(val) {}
};
//-思路:使用最小生成树算法，每次都找（曼哈顿距离）最短的一条且两点没有连通的边，判断连通需要用并查集
//-保存边的权重，则额外定义一个辅助类。
class Solution {
public:
    //-根据所有边建立最小生成树
    int minCostConnectPoints(vector<vector<int>>& points) {
        //-根据所有点建立权重边
        vector<Edge> edges;
        for(int i = 0; i < points.size(); ++i){
            for (int j = i+1; j < points.size(); ++j) {
                int distence = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.emplace_back(i,j, distence);
            }
        }
        //-将边按权重排序
        sort(edges.begin(),edges.end(),[](Edge a,Edge b){
            return a.value<b.value;
        });
        UF uf((int)points.size());
        int fee = 0;
        for(auto &edge:edges){
            //-如果连接了就了略过
            if(uf.if_connected(edge.i,edge.j)){
                continue;
            }
            uf.connect(edge.i,edge.j);
            fee+=edge.value;
        }
        return fee;
    }
};