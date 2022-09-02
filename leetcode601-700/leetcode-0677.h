#include "utils.h"
// *设计数据结构满足以下功能：
// *insert：插入键值对，如果key存在则替换values
// *sum：返回所有以prefix为前缀的键key的值总和
struct TrieNode{
    int value;
    vector<TrieNode*> treelist;
    TrieNode():value(0){
        treelist.resize(26,nullptr);
    }
};
class MapSum {
private:
    TrieNode * root;
public:
    MapSum() {
        root = new TrieNode;
    }

    void insert(string key, int val) {
        TrieNode * temp = root;
        for(int i = 0;i<key.size();++i){
            int cindex = key[i]-'a';
            if(temp->treelist[cindex] == nullptr){
                temp-> treelist[cindex] = new TrieNode;
            }
            temp = temp->treelist[cindex];
        }
        temp->value = val;
    }

    int sum(string prefix) {
        //-先遍历到prefix
        TrieNode * temp = root;
        for(int i = 0;i<prefix.size();++i){
            int cindex = prefix[i]-'a';
            if(temp->treelist[cindex] == nullptr){
                return 0;
            }
            temp = temp->treelist[cindex];
        }
        return traceback(temp);
    }

    int traceback(TrieNode * root){
        int res = root->value;
        for(auto & child: root->treelist){
            if(child != nullptr){
                res+= traceback(child);
            }
        }
        return res;
    }
};