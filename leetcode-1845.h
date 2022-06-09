#include "utils.h"
// *设计座位预约管理系统，完成以下几个api
class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> pqueue;
public:
    //-思路：可以用优先级队列，每次取最小的并pop，退订以后就push
    // *初始化对象，管理1~n一共n个座位，每个座位初始都可预约
    SeatManager(int n) {
        for(int i = 1; i <= n; ++i){
            pqueue.push(i);
        }
    }

    // *返回可预约座位的最小编号，将座位变为不可预约
    int reserve() {
        int temp = pqueue.top();
        pqueue.pop();
        return temp;
    }

    // *将对应座位编号的座位变为可预约
    void unreserve(int seatNumber) {
        pqueue.push(seatNumber);
    }
};