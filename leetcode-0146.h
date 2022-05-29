#include "utils.h"
// *实现LRU缓存，给定容量，实现get和put方法
class LRUCache {
private :
    //-使用双向链表+unorderedmap组合实现一个hashlist，实现O(1)时间的查找，插入，删除
    //-listnode是key和value
    list<pair<int,int>> cache;
    //-key->list node it的映射
    unordered_map<int,list<pair<int,int>>::iterator> mmap;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(mmap.count(key)>0){
            //-提升该缓存优先级
            pair<int,int> cache_unit = *(mmap[key]);
            cache.erase(mmap[key]);
            //-队尾保留下来的优先级越高
            list<pair<int,int>>::iterator it = cache.insert(cache.end(),cache_unit);
            mmap[key] = it;
            return mmap[key]->second;
        }
        //-找不到key返回-1
        return -1;
    }

    void put(int key, int value) {
        if(mmap.count(key) > 0){
            //-如果已经存在 删除当前元素
            cache.erase(mmap[key]);
            //-在队尾插入新元素,相当于修改value和提升优先级两个操作同时实现了
            list<pair<int,int>>::iterator it = cache.insert(cache.end(),make_pair(key,value));
            mmap[key] = it;
        }else{
            //-如果不存在，在队尾插入
            list<pair<int,int>>::iterator it = cache.insert(cache.end(),make_pair(key,value));
            mmap[key] = it;
            //-如果容量超了，就弹出队头, 同时删除map里的记录
            if(cache.size()>cap){
                mmap.erase(cache.front().first);
                cache.erase(cache.begin());
            }
        }
    }
};