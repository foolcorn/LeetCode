#include "utils.h"
// *实现最大频率栈，出栈的是最大频率的那个数，如果频率相同的数有多个则pop最靠近栈顶的最大频率数
class FreqStack {
private:
    int maxcount;
    unordered_map<int,int> valtonum;
    unordered_map<int,vector<int>>numtolist;
public:
    //-思路：模仿LFU吧
    //-维护一个map，将每个元素,映射到对应的数量
    //-维护一个map，映射每个频率对应的列表（我这里用了vector）。
    //-因为相同频率的情况下，只需要pop最靠近栈顶的，所以每次找到maxcount对应的vector，
    //-把末尾元素删除即可。之后更新maxcount和valtonum
    //-本质上是把一个栈按频率切割成一个个部分了。
    FreqStack() {}
    void push(int val) {
        //-如果该元素第一次插入
        if(valtonum.count(val)==0){
            valtonum[val] = 1;
        }else{
            ++valtonum[val];
        }
        int ctemp = valtonum[val];
        //-更新maxcount
        maxcount = max(maxcount, ctemp);
        if(numtolist.count(ctemp)==0){
            numtolist[ctemp] = vector<int>();
        }
        //-将该元素放在对应count的位置上
        numtolist[valtonum[val]].push_back(val);
    }

    int pop() {
        vector<int>& vec = numtolist[maxcount];
        int res = vec.back();
        vec.pop_back();
        //-更新valtonum
        --valtonum[res];
        //-更新maxcount
        if(vec.empty()){
            --maxcount;
        }
        return res;
    }
};