#include "utils.h"
// *设计数据结构，支持添加单词，和查找字符串匹配正则表达式
// *正则表达式比较简单，如果有.意思是可以匹配任何一个字符
struct TrieNode{
    bool hasval;
    vector<TrieNode*> treelist;
    TrieNode(bool sign) : hasval(sign) {
        treelist.resize(26,nullptr);
    }
};
class WordDictionary {
private:
    TrieNode * root;
public:
    WordDictionary() {
        root = new TrieNode(false);
    }

    void addWord(string word) {
        TrieNode * temp = root;
        for(int i = 0;i<word.size();++i){
            int cindex = word[i]-'a';
            if(temp->treelist[cindex] == nullptr){
                temp-> treelist[cindex] = new TrieNode(false);
            }
            temp = temp->treelist[cindex];
        }
        temp->hasval = true;
    }

    bool search(string word) {
        return traceback(word, root, 0);
    }
    bool traceback(const string &word, TrieNode* temp, int start){
        for(int i = start;i<word.size();++i){
            if(word[i] == '.'){
                for(TrieNode* ele : temp->treelist){
                    if(ele!=nullptr&&traceback(word, ele,i+1)){
                        return true;
                    }
                }
                return false;
            }
            int cindex = word[i]-'a';
            temp = temp->treelist[cindex];
            if(temp == nullptr){
                return false;
            }
        }
        return temp->hasval;
    }
};