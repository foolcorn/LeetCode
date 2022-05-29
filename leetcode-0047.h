#include "utils.h"
// *有重复元素不重复取的排列
class Solution {
private:
    vector<vector<int>> res;
    vector<int> gnums;
    vector<bool> used;
    int length;
public:
    vector<vector<int>> permuteUnique(vector<int> nums) {
        gnums = nums;
        sort(gnums.begin(),gnums.end());
        length = nums.size();
        used = vector<bool>(length, false);
        vector<int> temp;
        traceback(temp);
        return res;
    }
    void traceback(vector<int> &temp){
        if(temp.size() == length){
            res.push_back(temp);
            return;
        }
        for(int i = 0;i<gnums.size();++i){
            //-这个确实忘了,要略过已经使用了的元素
            if(used[i]){
                continue;
            }
            //-如果没使用的要判断重复元素的使用，要一个个used->true，不能用后面的重复元素
            if(i>0 && gnums[i]==gnums[i-1] && used[i-1]){
                continue;
            }
            temp.push_back(gnums[i]);
            used[i] = true;
            traceback(temp);
            temp.pop_back();
            used[i] = false;
        }
    }
};
