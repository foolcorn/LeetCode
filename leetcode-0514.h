#include "utils.h"
// *自由之路，转轮盘，最初指针指向ring的第一个字符，计算不断转ring，一直匹配key中所有字符所需的最小步数
// *轮盘转动一格就是一步，将匹配字符转到12:00位置时按下确认按钮也算一步
class Solution {
    vector<vector<int>> memo;
    unordered_map<char,vector<int>> valtoindex;
    int maxvalue;
public:
    int findRotateSteps(string ring, string key) {
        maxvalue = ((int)ring.size()+1)*(int)key.size();
        memo = vector<vector<int>>(ring.size(),vector<int>(key.size(),0));
        for(int i= 0;i<ring.size();++i){
            char c = ring[i];
            valtoindex[c].push_back(i);
        }
        return steps(ring,key,0,0);
    }
    int steps(string &ring, string &key, int location, int start){
        if(start == key.size()){
            return 0;
        }
        if(memo[location][start]!=0){
            return memo[location][start];
        }
        int res = INT_MAX;
        for(int index:valtoindex[key[start]]){
            int step = abs(location-index);
            step = min(step,(int)ring.size()-step);//-这一步非常关键，因为从location走到index即可以顺时针走到该位置也可以逆时针，需要做些判断
            res = min(res,step+1+steps(ring,key,index,start+1));
        }
        memo[location][start] = res;
        return res;
    }
};