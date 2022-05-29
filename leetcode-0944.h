#include "utils.h"
// *二维数组，计算不按字典序递增的列数
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rowsize = (int)strs.size();
        int colsize = (int)strs[0].size();
        int count = 0;
        for(int col = 0;col<colsize;++col){
            vector<char> temp;
            for (int row = 0; row < rowsize; ++row){
                temp.push_back(strs[row][col]);
            }
            vector<char> temp_sort = temp;
            sort(temp_sort.begin(),temp_sort.end());
            if (temp!=temp_sort){
                ++count;
            }
        }
        return count;

    }
};