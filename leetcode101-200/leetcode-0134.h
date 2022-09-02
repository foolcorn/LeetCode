#include "utils.h"
// *加油站,gas[i]代表i加油站的油量，cost[i]代表从i到i+1的消耗，由于是环形，cost[end]则是从end到0的消耗
// *从哪个下标出发可以环绕一圈？如果没有答案返回-1
class Solution {
public:
    //-思路：从第一个下标开始走，假设此时油量为第一个加油站提供的油量,计算到达每一站时的油量变化
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //-记录到下一个加油站的油量，假设一开始是无油状态，从第一个加油站出发，获得第一个加油站的油并减去到第二个加油站的消耗就是到第二个加油站的剩余油量
        int gassum = 0;
        int mingas = 0;//-记录最低油量
        int minindex = 0;//-记录最低油量的index
        for(int i = 0;i<gas.size();++i){
            //-计算到下一个加油站的油量
            gassum = gassum+gas[i]- cost[i];
            if(gassum<mingas){
                mingas = gassum;
                minindex = i+1;
            }
        }
        //-如果走过了所有加油站，发现最后油量<0,说明总油量<总消耗，无解
        if(gassum<0){
            return -1;
        }
        return minindex == gas.size()? 0 : minindex;
    }
};