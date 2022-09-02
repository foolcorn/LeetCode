#include "utils.h"
// *n个节点，edges表示无向边关系，问能否构成一颗树结构
class UnionFind{
private:
    vector<int> parent;
    int count;
public:
    UnionFind(int n){
        for(int i = 0; i < n;++i){
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
    int find(int node){
        if(parent[node] != node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
    int count(){
        return count;
    }
};
class Solution {
public:
    //-思路：树结构不存在环，意味着加入新边的时候，如果两个节点已经是连通的，那就会构成环
    //-所以还是可以用并查集
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto & edge : edges){
            if(!uf.isConnected(edge[0],edge[1])){
                uf.connect(edge[0],edge[1]);
            }else{
                //-如果形成环，则必不为树
                return false;
            }
        }
        //-当不存在环,还要判断是否所有节点都连通,也就是只有一个连通分量
        return uf.count() == 1;
    }
};