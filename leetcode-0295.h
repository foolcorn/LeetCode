#include "utils.h"
// *高效率获得数据流的中位数
class MedianFinder {
    //-使用两个优先级队列
    //-下面的大顶堆
    priority_queue<int,vector<int>,less<int>> down;
    //-上面的小顶堆
    priority_queue<int,vector<int>,greater<int>> up;
public:
    MedianFinder() {}
    void addNum(int num) {
        //-判断哪个堆要插入,先插入
        //-如果down没元素直接插入
        if(down.empty()){
            down.push(num);
        }else if(num>down.top()){
            up.push(num);
        }else{
            down.push(num);
        }
        //-之后根据size调整两个堆平衡
        //-如果down太大,pop给up
        if(down.size()>up.size()+1){
            up.push(down.top());
            down.pop();
        }
        //-如果up太大,pop给down
        if(up.size()>down.size()+1){
            cout<<"hh";
            down.push(up.top());
            up.pop();
        }
    }
    double findMedian() {
        if(down.empty()&&up.empty()){
            return 0;
        }
        if (down.size() == up.size()) {
            return (double)(down.top()+up.top())/2;
        }else if(down.size()>up.size()){
            return down.top();
        }else{
            return up.top();
        }
    }
};