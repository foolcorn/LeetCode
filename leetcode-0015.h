#include "utils.h"
// *三数之和
class Solution {
private:
    vector<int> gnums;
    vector<vector<int>> res;
    int size = 0;
public:
    //-先写两数之和吧
    vector<vector<int>> twoSum(int start, int target){
        //-两数临时答案
        vector<vector<int>> temp;
        //-左右指针
        int left = start;
        int right = size-1;
        while(left<right){
            int sum = gnums[left]+gnums[right];
            if(sum>target){
                --right;
            } else if(sum<target){
                ++left;
            } else{
                //-temp加入元素,并略过所有重复元素
                temp.push_back({gnums[left++],gnums[right--]});
                while(left<size&&gnums[left]==gnums[left-1]){++left;}
                while(right>=0&&gnums[right]==gnums[right+1]){--right;}
                if(left>=right){
                    break;
                }
            }
        }
        return temp;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        gnums = nums;
        size = gnums.size();
        if(size<3){//-元素不足三个返回空集
            return res;
        }
        //-先排序
        sort(gnums.begin(),gnums.end());
        //-临时的答案数组
        vector<vector<int>> temp;
        for(int i = 0;i<gnums.size();++i){
            //-这就是排序的原因之一了,记得略过重复的元素
            if(i>0&&gnums[i] == gnums[i-1]){
                continue;
            }
            temp = twoSum(i+1,-gnums[i]);
            for(auto &ele:temp){
                //-插入第三个元素
                ele.push_back(gnums[i]);
                //-更新答案
                res.push_back(ele);
            }
        }
        return res;
    }
};