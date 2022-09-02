#include "utils.h"
// *给定等式方程==和!=两种关系，判断所有等式方程可以同时成立吗
class UF{
private:
    //-记录每个元素的父亲是谁
    vector<int> parent;
    //-记录不连通分量的数量
    int count;
public :
    UF(int n){
        //-每个节点的父亲初始都是自己
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
        }
        count = n;
    }
    //-把a和b连接起来
    void connect(int a, int b){
        //-先找两个节点的根
        int root1 = find(a);
        int root2 = find(b);
        //-如果已经连通，就不用再连了
        if(root1 == root2){
            return;
        }
        parent[root2] = parent[root1];
        --count;
    }
    //-判断 a和b是否连通
    bool if_connected(int a,int b){
        return find(a) == find(b);
    }
    //-寻找节点的根
    int find(int node){
        if(parent[node]!=node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //-一共有26个字母的可能
        UF uf(26);
        //-先利用等式把所有节点连通
        for(string eqution:equations){
            if(eqution[1] == '='){
                uf.connect(eqution[0]-'a',eqution[3]-'a');
            }
        }
        //-利用不等式判断是否冲突
        for(string eqution:equations){
            if(eqution[1] == '!'){
                if(uf.if_connected(eqution[0]-'a',eqution[3]-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};