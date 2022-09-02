#include "utils.h"
// *用栈来实现队列(题目保证所有操作都是有效的，不用考虑空队列pop等情况)
class MyQueue {
    vector<int> vstack1;
    vector<int> vstack2;
public:
    MyQueue() {}

    //-有元素进队列,先入栈1
    void push(int x) {
        vstack1.push_back(x);
    }

    //-出队，如果栈2还有元素，就从栈2出栈直到出完为止，如果栈2为空，则把当前的所有栈1元素倒序进栈2，然后pop栈头即可
    int pop() {
        int res;
        if(!vstack2.empty()){
            res = vstack2.back();
            vstack2.pop_back();
        }else{
            while(!vstack1.empty()){
                vstack2.push_back(vstack1.back());
                vstack1.pop_back();
            }
            res = vstack2.back();
            vstack2.pop_back();
        }
        return res;
    }

    //-和pop同理
    int peek() {
        if(vstack2.empty()){
            while(!vstack1.empty()){
                vstack2.push_back(vstack1.back());
                vstack1.pop_back();
            }
        }
        return vstack2.back();
    }

    bool empty() {
        return vstack1.empty()&&vstack2.empty();
    }
};