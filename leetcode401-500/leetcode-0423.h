#include "utils.h"
// * 字母    	数字
// * e	    0 1 3 5 7 8 9
// * f	    4 5
// * g	    8
// * h	    3 8
// * i	    5 6 8 9
// * n	    1 7 9
// * o	    0 1 2 4
// * r	    0 3 4
// * s	    6 7
// * t	    2 3 8
// * u	    4
// * v	    5 7
// * w	    2
// * x	    6
// * z	    0


// *从英文中重建数字
class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> c;
        for (char ch: s) {
            ++c[ch];
        }

        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};