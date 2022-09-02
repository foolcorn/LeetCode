#include "utils.h"
// *扁平化嵌套列表迭代器，提供了以下接口，isInterger判断当前是元素还是列表
// *getInteger() 获取当前元素的值，getList()获取当前元素扩展的列表
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    deque<NestedInteger> dlist;
public:
    //-思路：每次判断是否还有元素的时候,顺便判断首元素是不是整数,只要不是整数必拆开,直到首元素为整数为止.
    //-拆的方式也简单,pop头元素，如果是列表就按顺序pushfront回去，并保持原来的顺序，所以我用了反向迭代器
    NestedIterator(vector<NestedInteger> &nestedList) {
        //-使用双端队列来模拟一个链表
        dlist = deque<NestedInteger>(nestedList.begin(),nestedList.end());
    }
    int next() {
        int temp = dlist.front().getInteger();
        dlist.pop_front();
        return temp;
    }

    bool hasNext() {
        while(!dlist.empty()&&!dlist.front().isInteger()){
            vector<NestedInteger> temp = dlist.front().getList();
            dlist.pop_front();
            for (auto it = temp.rbegin(); it != temp.rend(); ++it) {
                dlist.push_front(*it);
            }
        }
        return !dlist.empty();
    }
};
