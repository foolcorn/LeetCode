#include "utils.h"
// * 最小跳跃次数
class Solution {
private:
    int f[10000000 + 7];
    int maxdis[10000000 + 7];
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        int w = 0;
        int ans = 1000000000;

        for (int i=1; i<=n; ++i) {
            f[i] = 1000000000;
            maxdis[i] = 0;
        }
        f[1] = 0;
        maxdis[0] = 1;

        for (int i=1; i<=n; ++i) {
            if (i > maxdis[w]) { //- 更新单调指针
                ++w;
            }
            f[i] = min(f[i], w+1); //- 用 maxdis[w] 更新 f[i]
            int next = i + jump[i-1]; //- 第一步跳跃更新

            if (next > n) {
                ans = min(ans, f[i] + 1);
            } else if (f[next] > f[i] + 1) {
                f[next] = f[i] + 1;
                maxdis[f[next]] = max(maxdis[f[next]], next);
            }
        }

        return ans;
    }
};