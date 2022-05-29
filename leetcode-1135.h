#include "utils.h"
// *给定n个城市1~n：给定connections，每个元素是三元组 connections[i] = [xi, yi, costi]
// *costi表示连接成本，问连接完所有城市的最低成本，如果无法连接所有城市返回-1
class UnionFind{
private:
    vector<int> parent;
    int count;
public:
    UnionFind(int n){
        for(int i=0; i<n; ++i){
            parent.push_back(i);
        }
        count = n;
    }
    void connect(int node1, int node2){
        int root1 = find(node1);
        int root2 = find(node2);
        if(root1 == root2){
            return;
        }
        parent[root2] = root1;
        --count;
    }
    bool isConnected(int node1, int node2){
        return find(node1) == find(node2);
    }
    int connectCount() const{
        return count;
    }
    int find(int node){
        if(parent[node] != node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};
class Solution {
public:
    //-思路：还是使用生成树配合并查集，最后判断连通分量的数量判断是否能连接所有城市
    //-因为城市下标从1开始，所以，需要把下标都减一
    int minimumCost(int n, vector<vector<int>>& connections) {
        //-连接费用
        int fee = 0;
        //-先按costi排序
        sort(connections.begin(), connections.end(),[](vector<int> a,vector<int> b){
            return a[2]<b[2];
        });
        //-建立并查集类
        UnionFind uf(n);
        for(auto& edge:connections){
            if(uf.isConnected(edge[0]-1,edge[1]-1)){
                //-如果两个城市已经连接，就忽略
                continue;
            }else{
                uf.connect(edge[0]-1,edge[1]-1);
                fee+=edge[2];
            }
        }
        //-最后判断连通分量
        return uf.connectCount() == 1?fee:-1;
    }
};