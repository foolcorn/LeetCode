#include "utils.h"
// *计算右侧小于当前元素的个数
//-构造一个类来存value和index,index主要是用来更新res用的
struct Node{
    int val;
    int index;
    Node(int v, int i):val(v), index(i){}
};
class Solution {
private:
    vector<int> res;
    vector<Node> temp;
public:
    //-思路,先把元素转成Node,然后对Node使用归并排序,在归并排序的时候,
    //-如果从temp插入到num的是左边的元素,此时更新该元素对应index的res,增量==ptr2-mid-1，其它和普通归并一致
    vector<int> countSmaller(vector<int>& nums) {
        vector<Node> nnums;
        res = vector<int>(nums.size(),0);
        temp = vector<Node>(nums.size(),Node(0,0));
        for(int i = 0;i<nums.size();i++){
            nnums.emplace_back(nums[i],i);
        }
        mergesort(nnums,0,nnums.size()-1);
        return res;
    }
    void mergesort(vector<Node>& nnums,int low,int high){
        if(low == high) return;
        int mid = low + (high-low)/2;
        mergesort(nnums,low,mid);
        mergesort(nnums,mid+1, high);
        merge(nnums,low,mid,high);
    }
    void merge(vector<Node>& nnums,int low, int mid, int high){
        for(int i = low; i <= high; ++i){
            temp[i] = nnums[i];
        }
        int ptr1 = low;
        int ptr2 = mid+1;
        for(int i = low;i<=high;++i){
            if(ptr1 == mid+1){
                nnums[i] = temp[ptr2++];
            }else if(ptr2 == high+1){
                nnums[i] = temp[ptr1++];
                res[nnums[i].index]+=ptr2-mid-1;
            }else if(temp[ptr1].val>temp[ptr2].val){
                nnums[i] = temp[ptr2++];
            }else {
                nnums[i] = temp[ptr1++];
                res[nnums[i].index]+=ptr2-mid-1;
            }
        }
    }
};
