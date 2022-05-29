#include "utils.h"
// *区间加法 length是数组长度，updates为[startIndex, endIndex, inc]
class Diff{
private:
    vector<int> temp;
public:
    Diff(int n){
        temp = vector<int>(n,0);
    }
    void increment(int i, int j, int increase){
        temp[i] += increase;
        if(j+1<temp.size()){//-加这个条件，就是为了防止[i,j]这个区间在原数组就是数组末尾的区间了
            temp[j+1] -= increase;//-i，j不会溢出，但是j+1可能会溢出
        }
    }
    vector<int> result(){
        vector<int> res(temp);
        for(int i = 1;i<temp.size();++i){
            res[i] = res[i-1]+temp[i];
        }
        return res;
    }
};
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        Diff diff(length);
        for(auto &update:updates){
            diff.increment(update[0],update[1],update[2]);
        }
        return diff.result();
    }
};