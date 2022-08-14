#include "utils.h"
// *无重叠区间，给定区间集合，返回移除区间的最小数量，使剩余的区间相互不重叠
class Solution {
public:
    //-思路：这就是广联达的笔试题嘛.....尽可能地多安排面试，即使找出最多的互不重叠区间
    //-每次选最早结束的一个，然后把和这个区间相交的区间删掉
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //-按end来排序，这里是关键，如果不用引用会超时
        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        int deleteNum = 0;
        int end = intervals[0][1];
        for(int i = 1;i<intervals.size();++i){
            int start = intervals[i][0];
            //-如果和当前最短有相交
            if(start < end){
                ++deleteNum;
            }else{//-如果没有相交，则当前的区间一定是最快结束的，更新end
                end = intervals[i][1];
            }
        }
        return deleteNum;
    }
};

