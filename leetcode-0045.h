#include "utils.h"
// *nums[i]代表从i开始能走的步数，从0开始跳跃，假设总能到达最后一个下标，问最少的跳跃次数
class Solution {
public:
    //-思路,每一步都选择能跳跃到最长区域的位置去跳
    int jump(vector<int>& nums) {
        if(nums.size() == 1){//-判断初始位置就是终点的baseclass
            return 0;
        }
        int count = 0;
        int start = 0;
        while(true){
            int size = nums[start];
            int maxjump = start;
            int newindex = start;
            for(int i = 1;i<=size;++i){//-注意增量从1开始，i只是代表跳跃步数，index才是下标
                int index = start+i;
                if(index == nums.size()-1){//-如果下标已经能到达终点，因为跳跃才会++count,所以其实少了一次++count,所以要+1
                    return count+1;
                }
                if(index+nums[index]>=maxjump){//-选择最大潜力范围的去跳
                    maxjump = index+nums[index];
                    newindex = index;
                }
            }
            if(newindex>start){//-新坐标>初始坐标，就加跳跃次数
                ++count;
            }
            start = newindex;
        }
    }
};