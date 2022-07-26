#include "utils.h"
// *nums[i]代表从i开始能走的步数（可以自己选走几步），现在从0下标开始跳跃，判断是否能跳到最后一个下标
class Solution {
public:
    //-思路：每次在跳跃范围内,都跳到最大数值的地方
    bool canJump(vector<int>& nums) {
        int start = 0;
        if(nums.size() == 1){
            return true;
        }
        while(true){
            int size = nums[start];
            int maxtemp = start;
            int maxindex = 0;
            for(int i = 1;i<=size;++i){//-从1开始，i只是代表跳跃步数，index才是下标
                int index = start+i;
                if(index>=nums.size()-1){
                    return true;
                }
                if(index+nums[index]>=maxtemp){//-选择该位置跳跃的潜力范围是index+num[index]
                    maxtemp = index+nums[index];//- “>=”是因为后面的index总比前面的好，覆盖掉
                    maxindex = index;
                }
            }
            if(maxtemp == start){//-如果所有潜力范围为0
                return false;
            }
            start = maxindex;
        }
    }
};
