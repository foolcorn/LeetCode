#include "utils.h"
// *给定一个黑名单，使用pick能等概率返回0-n-1中的任意一个随机数，且不在黑名单中。
// *需要尽可能地少调用rand
class Solution {
private:
    unordered_map<int,int> mmap;
    int randrange;
public:
    //-思路：关键在于如何能让黑名单里的数字全都排列到队列的最后，这样我们在数组的有效范围内rand一个数返回即可
    //-一个方法是从前面开始遍历，如果遇到黑名单的数字，就将其映射到后面的非黑名单数字
    //-类似双指针的思维，一个从前往后，一个从后往前
    //-不过需要注意两点例外，一个是右指针的元素如果在黑名单里就跳过，
    Solution(int n, vector<int>& blacklist) {
        for(auto &black : blacklist){
            mmap[black] = -1;
        }
        randrange = n-(int)blacklist.size();
        int right = n-1;
        for(auto &left:blacklist){
            //-当左指针是randrange范围外的元素，也就是之前右指针跳过的元素，就不需要映射，
            //-主要是blacklist是无序的，不然如果left>randrange即可break
            if(left>=randrange){
                continue;
            }
            //-判断当前右指针的元素,是否在黑名单中，是则跳过
            while(mmap.count(right) > 0){
                --right
            }
            mmap[left] = right;
            --right;
        }
    }
    int pick() {
        int index = rand()%randrange;
        if(mmap.count(index)>0){
            return mmap[index];
        }else{
            return index;
        }
    }
};