#include "utils.h"
// *实现LFU缓存
class LFUCache {
private:
    //-键值映射
    unordered_map<int,int>key_to_value;
    //-维护每个key的使用计数
    unordered_map<int,int>key_to_count;
    //-对于每一个计数则维护一个key列表，表明了时间上的顺序
    unordered_map<int,list<int>>count_to_keylist;
    //-为了使这个key列表能有O（1）的查找效率，需要键映射到对应的list中的迭代器
    unordered_map<int,list<int>::iterator>key_to_listit;
    //-记录当前最小访问次数
    int min_count = 1;
    //-记录容量
    int cap;
public:
    LFUCache(int capacity):cap(capacity) {}

    int get(int key) {
        //-当前没有元素
        if(cap == 0){
            return -1;
        }
        //-如果key不存在
        if(key_to_value.count(key) == 0){
            return -1;
        }
            //-如果key存在，需要更新访问计数
        else {
            //-从上个count_to_keylist表中移除
            count_to_keylist[key_to_count[key]].erase(key_to_listit[key]);
            //-增加计数器
            ++key_to_count[key];
            //-在新的count_to_keylist列表后插入
            if(count_to_keylist.count(key_to_count[key]) == 0){
                count_to_keylist[key_to_count[key]] = list<int>();
            }
            list<int>::iterator it = count_to_keylist[key_to_count[key]].insert(count_to_keylist[key_to_count[key]].end(),key);
            //-更新迭代器列表
            key_to_listit[key] = it;
            //-更新最小值，如果刚刚访问的元素就是最小值的元素，则要判断还有没有剩余的最小值元素。
            while(count_to_keylist[min_count].empty()){
                ++min_count;
            }
            //-返回值
            return key_to_value[key];
        }
    }

    void put(int key, int value) {
        if(cap == 0){
            return;
        }
        //-若key不存在
        if(key_to_value.count(key) == 0){
            //-当前是否已经满容量
            if(key_to_value.size() == cap){
                //-删除最不常用的节点
                int key = count_to_keylist[min_count].front();
                count_to_keylist[min_count].erase(count_to_keylist[min_count].begin());
                key_to_value.erase(key);
                key_to_count.erase(key);
                key_to_listit.erase(key);
            }
            //-插入新节点
            key_to_value[key] = value;
            key_to_count[key] = 1;
            //-新元素肯定拥有最小访问次数1
            min_count = 1;
            //-插入conut链表，并更新迭代器列表
            if(count_to_keylist.count(1) == 0){
                count_to_keylist[1] = list<int>();
            }
            list<int>::iterator it = count_to_keylist[1].insert(count_to_keylist[1].end(),key);
            key_to_listit[key] = it;
        }
        //-若该key已经存在
        else {
            key_to_value[key] = value;
            //-从上个count_to_keylist表中移除
            count_to_keylist[key_to_count[key]].erase(key_to_listit[key]);
            //-增加计数器
            ++key_to_count[key];
            //-在新的count_to_keylist列表后插入
            if(count_to_keylist.count(key_to_count[key]) == 0){
                count_to_keylist[key_to_count[key]] = list<int>();
            }
            list<int>::iterator it = count_to_keylist[key_to_count[key]].insert(count_to_keylist[key_to_count[key]].end(),key);
            //-更新迭代器列表
            key_to_listit[key] = it;
            //-更新最小值
            while(count_to_keylist[min_count].empty()){
                ++min_count;
            }
        }
    }
};
