#include "utils.h"
// *使用队列实现栈
class MyStack {
private:
    deque<int> temp;
public:
    MyStack() {}

    //-每次入栈后，先把里面元素全部循环一遍
    void push(int x) {
        int size = (int)temp.size();
        temp.push_back(x);
        for(int i =0;i<size;++i){
            temp.push_back(temp.front());
            temp.pop_front();
        }
    }

    //-弹栈的时候弹最前面的即可
    int pop() {
        int res = temp.front();
        temp.pop_front();
        return res;
    }

    int top() {
        return temp.front();
    }

    bool empty() {
        return temp.empty();
    }
};
