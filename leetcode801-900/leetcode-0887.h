#include "utils.h"
// *鸡蛋掉落：给定楼层n，鸡蛋数k，鸡蛋在1~n中可以找到任意一层f，使得从该层掉下不会碎，而高于该层鸡蛋就会碎
// *问计算出f具体值的最小操作数
class Solution {
private:
    vector<vector<int>> memo;
public:
    int superEggDrop(int k, int n) {
        memo = vector<vector<int>>(n+1,vector<int>(k+1,-1));
        return traceback(n,k);
    }
    //-状态,搜寻范围,剩余鸡蛋
    int traceback(int range, int less){
        if(less == 1){
            return range;//-只剩一个鸡蛋的时候只能线性扫描
        }
        if(range == 0){
            return 0;//-搜寻范围为0时，不需要验证次数
        }
        if(memo[range][less]!=-1){
            return memo[range][less];
        }
        //-二分法主要是为了在1~range寻找到一个mid，使得max(traceback(mid-1, less-1),traceback(range-mid,less))最小
        //-为什么是max，因为鸡蛋可能碎可能不碎，使用max就可以忽略碎不碎这个状态对结果的影响，而答案就是要找到让这个max最小的楼层mid
        //-由于一个单增，一个单减，最大值曲线是一个V型图，要找到最小值，就是两个函数相交的点就是mid
        int left = 1;
        int right = range;
        while(left < right){
            int mid = left +(right-left)/2;
            //-如果单增的曲线在单减的曲线上面，以图像的角度，此时的target在mid的左边，需要收缩右边界
            if(traceback(mid-1, less-1)>traceback(range-mid,less)){
                right = mid;
            }else if(traceback(mid-1, less-1)<traceback(range-mid,less)){
                left = mid+1;
            }else{
                memo[range][less] = 1+traceback(mid-1,less-1);
                return memo[range][less];
            }
        }
        memo[range][less] = 1+max(traceback(left-1,less-1), traceback(range-left,less));
        return memo[range][less];
    }
};