#include "utils.h"
// * 最小栈
//-这题的难点并不是push元素后计算min，而是pop后还能算出min
class MinStack {
private:
    vector<int> eles;
    vector<int> mineles;
public:
    MinStack() {
    }

    void push(int val) {
        eles.push_back(val);
        int mintemp = val;
        if(!mineles.empty()) {
            mintemp = min(mintemp,mineles.back());
        }
        mineles.push_back(mintemp);
    }
     bool

    void pop() {
        eles.pop_back();
        mineles.pop_back();
    }

    int top() {
        return eles.back();
    }

    int getMin() {
        return mineles.back();
    }
};