#include "utils.h"
// *会议室2 给定区间数组，每个元素指定了会议的开始时间和结束时间，问最少需要多少会议室
// -思路：其实就是在问同一个时间内最多有多少区间重叠。
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //-把会议的开始时间点和结束时间点分别抽离出来
        vector<int>startpoints;
        vector<int>endpoints;
        for(int i = 0;i<intervals.size();++i){
            startpoints.push_back(intervals[i][0]);
            endpoints.push_back(intervals[i][1]);
        }
        //-分别排序
        sort(startpoints.begin(),startpoints.end());
        sort(endpoints.begin(),endpoints.end());
        //-结果
        int maxcount = 0;
        int count = 0;
        //-双指针
        int sptr = 0;
        int eptr = 0;
        //-有点括号匹配的意思了，sptr是左括号，eptr是右括号
        while(sptr<startpoints.size()){
            //-当存在某个会议开始在某个会议结束之前
            if(startpoints[sptr]<endpoints[eptr]){
                ++count;
                //-考虑下一个会议的开始
                ++sptr;
            }
                //-当某个会议结束了，下个会议还没开始
            else{
                --count;
                //-考虑下个会议的结束时间
                ++eptr;
            }
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};