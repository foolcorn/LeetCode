#include "utils.h"
// *给定区间列表，删除表中被其它区间覆盖的区间，返回剩余的区间数量
bool shorter(vector<int>&a, vector<int>&b){
    //-起点相等时,按终点逆序排序
    if(a[0]==b[0]){
        return a[1]>b[1];
    }
    //-按起点升序排序
    return a[0]<b[0];
}

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //-按起点升序排序，按终点降序排序
        sort(intervals.begin(), intervals.end(),shorter);
        int size = (int)intervals.size();
        //-为什么只有end没有start,因为已经按起点升序排序了
        //-end保存上一个temp的end
        int end = intervals[0][1];
        //-答案
        int res = 0;
        for(int i = 1;i<size;++i){
            vector<int> temp = intervals[i];
            //-由于按起点升序排序,所以temp起点一定>=上一个temp起点(假设有个start)
            //-如果temp终点<=上一个的temp终点(end),说明区间被覆盖
            if(temp[1]<=end){
                ++res;
                continue;
            }
            //-temp的start>之前的end，说明是新的区间了，更新衡量的标准end
            if(temp[0]>end){
                end = temp[1];
                continue;
            }
            //-如果只是部分覆盖，就更新end为上一个temp的end
            end = temp[1];
        }
        return size-res;
    }
};