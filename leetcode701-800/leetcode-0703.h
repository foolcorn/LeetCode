#include "utils.h"
// *实现api，获取数据流中第k大元素
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pqueue;
    int k;
public:
    //-思路：使用一个固定k大小的优先级队列（小顶堆）,每次都push,pop后,返回头元素即可
    // *指定了k和初始的整数流
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        //-先把所有入队,然后pop到只剩k个元素
        for(auto &num:nums){
            pqueue.push(num);
        }
        int size = (int)nums.size() - k;
        for(int i = 0;i<size;++i){
            pqueue.pop();
        }
    }
    // *从数据流中不断add value，同时返回当前第k大元素
    int add(int val) {
        pqueue.push(val);
        if(pqueue.size()>k){
            pqueue.pop();
        }
        return pqueue.top();
    }
};