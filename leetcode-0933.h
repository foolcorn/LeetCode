#include "utils.h"
// *返回3000毫秒内的所有请求，每次ping返回[t-3000,t]内请求数
class RecentCounter {
private:
    deque<int> pings;
    int count;
public:
    RecentCounter() {
        count = 0;
    }
    int ping(int t) {
        pings.push_back(t);
        int time = t-3000;
        for(int i = 0; i < count; i++){
            if(pings.front()<time){
                pings.pop_front();
            }else{
                break;
            }
        }
        count = pings.size();
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
