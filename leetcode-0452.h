#include "utils.h"
// *给定points代表气球的左右边界，在这个范围内（闭区间）任意射箭可以引爆气球，问引爆所有气球最小弓箭数
class Solution {
public:
    //-思路：可以用贪心法，按end顺序排序，如果下一个start不超过end就跳过，如果超过，就更新end
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        int count = 1;
        int end = points[0][1];
        for(int i = 1; i < points.size();++i){
            int start = points[i][0];
            if(start>end){
                ++count;
                end = points[i][1];
            }
        }
        return count;
    }
};