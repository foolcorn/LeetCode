#include "utils.h"
// *无向图中的连通分量的数量
//-思路：建立并查集类
class UnionFind{
private:
    vector<int> parent;
    //-连通分量数
    int count;
public:
    UnionFind(int n){
        //-一开始每个节点的父亲是自己
        for(int i = 0; i <n;++i){
            parent.push_back(i);
        }
        count = n;
    }
    //-返回未连接的连通分量的数量
    int connectCount(){
        return count;
    }
    //-将两个节点连接在一起
    void connect(int node1,int node2){
        int root1 = find(node1);
        int root2 = find(node2);
        if(root1 == root2){
            return;
        }
        //!这个是错的
//        parent[node2] = node1;
        //-是把root连接在一起，不是节点！
        parent[root2] = root1;
        --count;
    }
    //-判断两个节点是否连通
    bool isConnected(int node1,int node2){
        return find(node1) == find(node2);
    }
    //-查找节点的root
    int find(int node){
        //!这里是if，不是while！！,因为本来就有递归了
        if(parent[node]!=node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto& edge:edges){
            uf.connect(edge[0],edge[1]);
        }
        return uf.connectCount();
    }
};