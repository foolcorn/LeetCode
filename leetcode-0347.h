#include "utils.h"
// *前k个高频元素
class Solution {
public:
    bool cmp(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int,int> counts_map;
        for(int i = 0; i < nums.size();++i){
            counts_map[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>,cmp> pqueue;
        for(auto it = counts_map.begin();it!=counts_map.end();++it){
            pqueue.push(*it);
        }
        vector<int> res;
        for(int i = 0; i < k;++i){
            res.push_back(pqueue.top());
            pqueue.pop();
        }
        return res;
    }
};
