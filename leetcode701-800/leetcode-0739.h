#include "utils.h"
// *每日温度，给定每天的温度，求要多多少天才有下一个更高温度
class Solution {
public:
    //-思路：还是使用单调栈,不过可以构造一个类存val和index,也可以直接存index,不能用map因为可能存在重复温度
    //-我原来使用存index的栈来做的，这次我就用pair来实现吧
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<pair<int,int>> vstack;
        vector<int> res(temperatures);
        for(int i = temperatures.size()-1;i>=0;--i){
            while(!vstack.empty()&&temperatures[i]>=vstack.back().first){
                vstack.pop_back();
            }
            res[i] = vstack.empty()? 0 : vstack.back().second-i;
            vstack.emplace_back(temperatures[i],i);
        }
        return res;
    }
};