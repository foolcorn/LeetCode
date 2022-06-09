#include "utils.h"
// *视频拼接，给定区间列表，求最少取多少区间可以覆盖[0,time]区间
class Solution {
public:
    //-思路：贪心,先选0开始的，跨度最长的，然后在结束之前再次选跨度最长的
    //-因为需要判断下一次的开始要在上一次end之前或者相等，所以应该是先按起点排序,
    //-然后如果是起点相同，就按end降序排序，保证第一个更新的end就是跨度最长的end
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](vector<int>& a,vector<int> & b){
            if(a[0] == b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });

        int count = 1;
        int start = clips[0][0];
        int end = clips[0][1];
        if(start>0){//-如果第一个区间就不满足覆盖0
            return -1;
        }
        if(end>=time){//-如果第一个区间就覆盖了time
            return 1;
        }
        int maxend = clips[0][1];
        bool sign = false;
        for(int i = 1;i<clips.size();++i){
            int cur_start = clips[i][0];
            int cur_end = clips[i][1];
            //-如果start超过上个区间终点,立刻选择最长maxend作为新的end构成新的区间
            if(cur_start>end){
                end = maxend;
                sign = false;//-因为是新的区间来求一个结束（end）之前最大的maxend了，所以把标志置零
                if(cur_start>end){//-如果新区间和上一个区间不能衔接，返回-1
                    return -1;
                }
            }
            if(cur_end>maxend){//- 找到当前end之前的最大maxend了，并且只要找到一次就增加计数，在新区间建立之前最多只会增加一次。但是maxend会始终更新
                maxend = cur_end;
                if(!sign){
                    sign = true;
                    ++count;
                }
            }//-每次拓宽了maxend，就会判断一下当前是否已经走到终点
            if(maxend>=time){
                return count;
            }
        }
        return -1;
    }
};

//-旧版也许好理解一点，但是很冗长
class Solution_old {
public:
    //-思路：贪心,先选0开始的，跨度最长的，然后在结束之前再次选跨度最长的
    //-因为需要判断下一次的开始要在上一次end之前或者相等，所以应该是先按起点排序,
    //-然后如果是起点相同，就按end降序排序，保证第一个更新的end就是跨度最长的end
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](vector<int>& a,vector<int> & b){
            if(a[0] == b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        for(auto ele:clips){
            cout<<"["<<ele[0]<<","<<ele[1]<<"] ";
        }
        cout<<endl;

        int count = 1;
        int start = clips[0][0];
        if(start>0){
            return -1;
        }
        int end = clips[0][1];
        if(end>=time){
            return 1;
        }
        int maxend = clips[0][1];
        bool sign = false;
        for(int i = 1;i<clips.size();++i){
            int cur_start = clips[i][0];
            int cur_end = clips[i][1];
            //-如果start没超过上个区间终点,尝试更新maxend，对于所有这种情况，只要更新成功一个就会加一
            if(cur_start<=end){
                if(cur_end>maxend){
                    maxend = cur_end;
                    if(!sign){
                        sign = true;
                        ++count;
                    }
                }
            }else{//-如果start超过了上个区间终点，立刻选择最长maxend作为新的end构成新的区间
                end = maxend;
                sign = false;
                if(cur_start>end){
                    return -1;
                }
                if(cur_end>maxend){
                    maxend = cur_end;
                    if(!sign){
                        sign = true;
                        ++count;
                    }
                }
            }
            cout<<"count: "<<count<<" end: "<<end<<"   "<<endl;
            if(maxend>=time){
                return count;
            }
        }
        return -1;
    }
};