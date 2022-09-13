#include "utils.h"
// *四数之和
class Solution {
private:
    vector<int> gnums;
    vector<vector<int>> res;
    int size = 0;
public:
    //-将三数之和框架写成递归
    //-参数有三个：
    //- 1：int n:n数之和---2. int start:从start到end范围找元素---3: int target:n数和的target是多少
    vector<vector<int>> nSum(int n,int start, int target){
//        cout<<"n: "<<n<<" start: "<<start<<" target "<<target<<endl;
        //-设置n数和的临时答案，最后返回给上个递归
        vector<vector<int>> temp;
        if(n>2){
            for(int i = start;i<size;++i){
                //-记得略过重复的
                if(i>start && gnums[i] == gnums[i-1]){
                    continue;
                }
                //-从子递归获得答案，让n-1，start=i+1，target减去当前选中的num[i]
                vector<vector<int>> arr = nSum(n-1,i+1,target-gnums[i]);
                //-子递归的答案插入当前的元素,并返回
                for(vector<int> &ele:arr){
                    ele.push_back(gnums[i]);
                    temp.push_back(ele);
                }
            }
        }
        //-递归到两数之和
        if(n==2){
            int left = start;
            int right = size-1;
            while(left<right){
                int sum = gnums[left]+gnums[right];
                if(sum>target){
                    --right;
                } else if(sum<target){
                    ++left;
                } else{
                    //-插入当前答案
                    temp.push_back({gnums[left++],gnums[right--]});
                    while(left<size&&gnums[left] == gnums[left-1]){++left;}
                    while(right>=0&&gnums[right] == gnums[right+1]){--right;}
                    if(left>=right){
                        break;
                    }
                }
            }
        }
        return temp;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        gnums = nums;
        size = gnums.size();
        if(size<4){
            //-数量少于4,return 空
            return res;
        }
        sort(gnums.begin(),gnums.end());
        return nSum(4,0,target);
    }
};