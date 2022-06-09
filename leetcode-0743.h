#include "utils.h"
// *给定n个节点1~n，times[i] = (ui, vi, wi)，ui是源节点，vi是目标，wi是时间
// *问从节点k发出信号，每个节点收到信号的最短时间，如果不能使所有节点收到返回-1
class Node{
public:
    int num;
    int distance;
    Node(int x,int y):num(x), distance(y) {}
};
struct cmp{
    bool operator()(Node lhs, Node rhs){
        return lhs.distance > rhs.distance;

    }
};
class Solution {
private:
    //-全局保存当前节点到每一个节点的距离
    vector<int> distanceTo;
public:
    //-使用BFS框架实现dijkstra算法
    int networkDelayTime(vector<vector<int>> times, int n, int k) {
        //-根据当前的边建立图，因为有权重，所以需要Node的辅助类
        vector<vector<Node>> graph(n+1,vector<Node>());
        for(auto edge:times){
            graph[edge[0]].push_back(Node(edge[1],edge[2]));
        }
        //-初始化distance数组，表明k点到每个节点的初始长度是无穷大
        distanceTo = vector<int>(n+1,INT_MAX);
        distanceTo[0] = INT_MIN;//-这个节点只是个dummy,因为节点从1开始编号
        distanceTo[k] = 0;//-k点到自己的长度为0

        //-调用dijkstra算法更新distanceTo数组
        dijkstra(k,graph);

        //-遍历distanceTo数组，找到所有最短路径的最大值
        int maxdistance = 0;
        for(auto ele:distanceTo){
            maxdistance = max(maxdistance,ele);
        }
        //-如果有个节点连接不到，就返回-1
        return maxdistance == INT_MAX?-1:maxdistance;
    }
    void dijkstra(int start,vector<vector<Node>> &graph){
        //-先让节点入队
        priority_queue<Node,vector<Node>,cmp> pque;
        pque.push(Node(start,0));
        while(!pque.empty()){
            Node node = pque.top();
            pque.pop();
            //-如果某个节点到该点的路径比起始点k到该点的路径还长
            if(node.distance>distanceTo[node.num]){
                continue;
            }
            for(auto &neighbour:graph[node.num]){
                //-判断是否要选这个节点
                //-如果起始点到neighbour的路径大于起始点到node的路径加上node和neighbour之间的距离，就更新更小的
                int new_length = distanceTo[node.num]+neighbour.distance;
                if(distanceTo[neighbour.num]>new_length){
                    distanceTo[neighbour.num] = new_length;
                    pque.push(neighbour);
                }
            }
        }
    }
};