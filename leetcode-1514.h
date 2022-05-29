class GraphNode{
public:
    int dst;
    double prob;
    GraphNode(int d,double p):dst(d),prob(p){}
};
class cmpNode{
public:
    bool operator()(GraphNode a, GraphNode b){
        return a.prob<b.prob;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //-首先根据边和权重建图，由于是无向边,转成有向图需要两次操作
        vector<vector<GraphNode>> graph(n,vector<GraphNode>());
        for(int i = 0;i<edges.size();++i){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            double prob = succProb[i];
            //-建立双向边
            graph[node1].push_back(GraphNode(node2, prob));
            graph[node2].push_back(GraphNode(node1, prob));
        }
        return djstra(start,end,graph);
    }

    double djstra(int start,int end, vector<vector<GraphNode>> &graph){
        vector<double>probToDest;
        //-初始化概率路径
        for(int i = 0;i<graph.size();++i){
            probToDest.push_back(-1);
        }
        //-start到自己的概率为1
        probToDest[start] = 1;
        //-通过djstra找到start到end的最大概率路径
        priority_queue<GraphNode,vector<GraphNode>,cmpNode> pqueue;
        pqueue.push(GraphNode(start,1));
        while(!pqueue.empty()){
            GraphNode cur = pqueue.top();
            pqueue.pop();
            //-如果首次遇到end了，那即是最大概率路径
            if(cur.dst == end){
                return cur.prob;
            }
            //-如果从start到cur的路径小于probToDest的路径就continue
            if(cur.prob<probToDest[cur.dst]){
                continue;
            }
            //-如果目前从start到当前cur的prob是最大的，尝试以该点往外拓展新的路径
            for(auto&neighbour:graph[cur.dst]){
                //-如果从该点走到邻接点的概率是更大的,就更新prob值
                double newprob = probToDest[cur.dst]*neighbour.prob;
                if(newprob>probToDest[neighbour.dst]){
                    probToDest[neighbour.dst] = newprob;
                    pqueue.push(GraphNode(neighbour.dst,newprob));
                }
            }
        }
        //-一直找不到end,返回0;
        return 0;
    }
};