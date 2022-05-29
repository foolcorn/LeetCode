#include "utils.h"
// * 上下公交车，车上只有capacity个空位，trip[i] = [numPassengersi, fromi, toi]
class Diff{
private:
    vector<int> passanger;
public:
    Diff(int n) {
        //-定义差分数组的意义为passanger[i]为第i站的人相对于第i-1站的增量
        //-注意from to是从0开始计算的，0<=from<to<=1000也就是有1001个站
        //-当i==0时，i-1==-1站人数一定是0.所以nums[0]是可以直接作为passanger[0]的
        //-也就是说对于差分数组长度是和原数组一致的
        //-那么该题就可以用1001个长度的差分数组来表达每一站的增量
        passanger = vector<int>(n,0);
    }
    vector<int> result() {
        vector<int> temp;
        int sum = 0;
        for(int i = 0;i<passanger.size();++i){
            sum+=passanger[i];
            temp.push_back(sum);
        }
        return temp;
    }
    //-由于fromi和toi都是左闭右闭区间，乘客从i上车，意味着i对于i-1加了这么多人，从j下车，意味着j对于j-1少了这些人。
    void increment(int i, int j, int num){
        passanger[i]+=num;
        passanger[j]-=num;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = 1001;
        Diff nums(n);
        for(auto trip:trips){
            nums.increment(trip[1],trip[2],trip[0]);
        }
        vector<int> res = nums.result();
        for(auto ele:res){
            if(ele>capacity){
                return false;
            }
        }
        return true;
    }
};
