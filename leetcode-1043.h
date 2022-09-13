#include "utils.h"
// *分隔数组的最大和
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,0);
        int curMax=arr[0];
        dp[0]=curMax;
        for(int i=1;i<k;i++){
            curMax=max(curMax,arr[i]);
            dp[i]=curMax*(i+1);
        }
        for(int i=k;i<n;i++){
            for(int j=i-k;j<i;j++){
                dp[i]=max(dp[i],dp[j]+*max_element(arr.begin()+j+1,arr.begin()+i+1)*(i-j));
            }
        }
        return dp[n-1];

    }
};
