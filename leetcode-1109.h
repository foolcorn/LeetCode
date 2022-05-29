#include "utils.h"
// * 在区间内预定航班
class Diff{
private:
    vector<int> diffarr;
public:
    //-这里设成n+1的长度仅仅是因为increment的参数i，j是从1开始算的，这样方便，0索引元素永远用不到
    Diff(int n):diffarr(vector<int>(n+1,0)){}
    void icrement(int i, int j,int count){
        diffarr[i]+=count;
        if(j+1<diffarr.size()){
            diffarr[j+1]-=count;
        }
    }
    vector<int> result(){
        vector<int> temp;
        int sum = 0;
        //-从索引1开始恢复原数组
        for(int i =1;i<diffarr.size();++i){
            sum+=diffarr[i];
            temp.push_back(sum);
        }
        //-temp长度为n
        return temp;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        Diff dif(n);
        for(auto booking:bookings){
            dif.icrement(booking[0],booking[1],booking[2]);
        }
        return dif.result();
    }
};