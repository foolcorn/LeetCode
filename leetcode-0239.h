#include "utils.h"
// *滑动窗口的最大值
class maxQueue{
    //-该类是一个维持逆序的单调队列
    deque<int> temp;
public:
    //-新插入元素，比它小的全部popback掉，这样维持整体的逆序
    void push(int ele){
        while(!temp.empty()&&temp.back()<ele){
            temp.pop_back();
        }
        temp.push_back(ele);
    }
    //-单调队列是pop头部
    void pop(){
        temp.pop_front();
    }
    int front(){
        return temp.front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = k;
        maxQueue window;
        int temp = INT_MIN;
        //-先给window填满k个元素，期间算出第一个窗口的最大值，插入到vector
        for(int i = 0; i < k;++i){
            window.push(nums[i]);
            temp = max(temp,nums[i]);
        }
        vector<int> res = {temp};
        //-不断往右滑动窗口，right从k开始已经相当于滑动了一次窗口
        while(right!=nums.size()){
            int newele = nums[right];
            //-真正维护窗口的其实是left和right指针,利用left指针和window的最大元素比较
            //-如果要pop的元素就是最大的那个元素，就pop掉该元素。
            if(window.front() == nums[left]){
                window.pop();
            }
            //-新元素插入到合适的位置并pop掉无用元素
            window.push(newele);
            //-返回该临时窗口的最大值
            res.push_back(window.front());
            //-真正收缩窗口
            ++left;
            ++right;
        }
        return res;
    }
};