#include "utils.h"
// *给两个元素为区间的vector，返回两个列表区间的交集
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        //-设置双指针
        int p1 = 0;
        int p2 = 0;
        int end1 = firstList.size();
        int end2 = secondList.size();
        vector<vector<int>> res;
        while(p1<end1 && p2<end2){
            vector<int>tempa = firstList[p1];
            vector<int>tempb = secondList[p2];
            //-a表开头比b表结尾大，没有交集
            if(tempa[0]>tempb[1]){
                //-让b表指针前进
                ++p2;
                continue;
            }
            //-b表开头比a表结尾大，没有交集
            if(tempb[0]>tempa[1]){
                //-让a表指针前进
                ++p1;
                continue;
            }
            //-有重叠的部分的话，开头取最右边的（max），结尾取最左边的（min）
            res.push_back({max(tempa[0],tempb[0]),min(tempa[1],tempb[1])});
            //-a表结尾比b表右,b表当前的区间已经走完了,所以让b表指针前进
            if(tempa[1]>tempb[1]){
                ++p2;
            }else{
                //-b表结尾比a表右,a表当前的区间已经走完了,所以让a表指针前进
                ++p1;
            }
        }
        return res;
    }
};