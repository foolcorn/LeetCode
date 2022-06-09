#include "utils.h"
// *使用O(1)时间完成插入，删除，获取随机元素
class RandomizedSet {
    int size = 0;
    vector<int> temp;
    unordered_map<int,int> mmap;
public:
    //-思路：使用数组实现，并辅助一个map来映射值和索引，维护一个size元素，指定当前temp内有几个元素（其实也可以不用，用temp.size就好了）
    RandomizedSet() {}
    bool insert(int val) {
        if(mmap.count(val)==0){
            temp.push_back(val);
            mmap[val] = size;
            ++size;
            return true;
        }else{
            return false;
        }
    }
    //-删除元素的时候，就把对应元素和最后的元素交换即可。
    bool remove(int val) {
        if(mmap.count(val) > 0){
            int index = mmap[val];
            mmap[temp.back()] = index;
            swap(temp[index],temp.back());
            temp.pop_back();
            mmap.erase(val);
            --size;
            return true;
        }else{
            return false;
        }
    }
    int getRandom() {
        int index = rand()%size;
        return temp[index];
    }
};