#include "utils.h"
// *田忌赛马，优势洗牌，让num1相对于num2的优势最大
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        //-最后顺序是按nums2来的,所以要维护nums2中 ele到 index的映射,由于ele可能重复,所以不能用map
        //-用pair保存每个元素的索引
        deque<pair<int,int>> new_nums2;
        for(int i = 0; i < nums2.size();++i){
            new_nums2.emplace_back(nums2[i], i);
        }
        //-降序排列吧
        sort(new_nums2.begin(),new_nums2.end(),[](pair<int,int>a,pair<int,int>b){
            return a.first>b.first;
        });
        //-将num1也降序排列
        sort(nums1.begin(),nums1.end(),[](int a,int b){return a>b;});
        //-最后结果集
        vector<int> res = nums1;
        //-指向num1目前最大的元素
        int left = 0;
        //-指向num2目前最小的元素
        int right = (int)nums1.size()-1;
        //-num1元素全部遍历完
        while(left<=right){
            int maxele = new_nums2.front().first;
            int index = new_nums2.front().second;
            new_nums2.pop_front();
            if(nums1[left]>maxele){
                res[index] = nums1[left];
                ++left;
            }else{
                res[index] = nums1[right];
                --right;
            }
        }
        return res;
    }
};