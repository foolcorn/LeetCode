#include "utils.h"
// *在days天内送完包裹的最低运载能力
class Solution {
private:
    vector<int> gweights;
public:
    int computeDays(int w){
        //-初始为1，如果刚好装完就是一天
        int days = 1;
        int less = w;
        for (int i = 0;i<gweights.size();++i){
            if(less>=gweights[i]){
                less -= gweights[i];
            } else{
                ++days;
                less = w-gweights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        this->gweights = weights;
        //-船的最低负载为货物的最大重量,保证一天至少装走一个货物
        int left = *max_element(weights.begin(), weights.end());
        //-船的最大负载为所有货物的总和，一天装完所有货物
        int right = accumulate(weights.begin(),weights.end(),0);
        //-依旧把w作为x轴，为递增序列
        //-computeDays和weight是反比，所以更新left和right是相反的。
        //-当不同w映射到同样的days时，找days左边界，因为对应的是最小的weights。
        //-所以==的时候，收缩右边界
        找computeday的左边界days
        while(left<=right){
            int mid = left+(right-left)/2;
            cout<<mid<<endl;
            if(computeDays(mid)>days){
                left = mid+1;
            } else if(computeDays(mid)<=days){
                right = mid-1;
            }
        }
        return left;
    }
};