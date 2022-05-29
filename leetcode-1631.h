struct GraphNode{
    int node;
    int val;
    GraphNode(int n,int v):node(n),val(v){}
};
struct cmpNode{
    bool operator()(GraphNode node1,GraphNode node2) {
        return node1.val>node2.val;
    }
};
class Solution {
public:
    //-这题的关键在于怎么把体力消耗转换成djstra算法的思路，消耗的体力并不是总消耗而是最大值。
    //-所以我们原来需要维护的dst数组的更新条件需要改变，不再是总消耗更小才更新，而是到该点的某个消耗更小才更新
    int minimumEffortPath(vector<vector<int>>& heights) {
        //-难点在于把二维数组（还是无向边）建成有向图
        int rows = (int)heights.size();
        int cols = (int)heights[0].size();
        int nodenums = rows*cols;
        vector<vector<GraphNode>> graph(nodenums,vector<GraphNode>());
        for(int i = 0;i<rows;++i){
            for (int j = 0; j < cols; ++j) {
                //-每个节点只要和其右节点和下节点建立双边的关系
                int node1 = cols*(i)+j;
                //-如果下有节点
                if(i+1<rows){
                    int node2 = cols*(i+1)+j;
                    int val = abs(heights[i+1][j]-heights[i][j]);
                    graph[node1].push_back(GraphNode(node2,val));
                    graph[node2].push_back(GraphNode(node1,val));
                }
                //-如果右有节点
                if(j+1<cols){
                    int node2 = cols*(i)+j+1;
                    int val = abs(heights[i][j+1]-heights[i][j]);
                    graph[node1].push_back(GraphNode(node2,val));
                    graph[node2].push_back(GraphNode(node1,val));
                }
            }
        }
        //-左上角坐标是0
        int start = 0;
        //-右下角坐标是nodenums-1
        int end = nodenums-1;
        return djstra(start,end,graph);
    }
    int djstra(int start, int end, vector<vector<GraphNode>> &graph){
        vector<int>dstVal(graph.size(),INT_MAX);
        dstVal[start] = 0;
        //-建立小顶堆的优先级队列
        priority_queue<GraphNode,vector<GraphNode>,cmpNode>pqueue;
        //-首元素入队
        pqueue.push(GraphNode(start,0));
        while(!pqueue.empty()){
            GraphNode cur = pqueue.top();
            pqueue.pop();
            if(cur.node == end){
                return cur.val;
            }
            //-如果维护的最短路径已经被取代了，就丢弃
            if(cur.val>dstVal[cur.node]){
                continue;
            }
            for(auto& neighbour:graph[cur.node]){
                //-计算如果走从当前节点到neighbour的最小体力消耗是多少
                //-最小体力，则取决于之前的最小消耗体力和当前消耗体力的最大值
                int maxval = max(dstVal[cur.node],neighbour.val);
                if(maxval<dstVal[neighbour.node]){
                    dstVal[neighbour.node] = maxval;
                    pqueue.push(GraphNode(neighbour.node,minval));
                }
            }
        }
        return dstVal[end];
    }
};