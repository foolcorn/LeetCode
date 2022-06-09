#include "utils.h"
// *实现前缀树
struct TrieNode{
    //-遍历到某个节点为止是否有值
    bool hasval = false;
    vector<TrieNode*> sons = vector<TrieNode*>(256,nullptr);
    TrieNode(bool sign):hasval(sign){}
};

class Trie {
private:
    TrieNode *root = new TrieNode(false);;
public:
    Trie() {
    }
    //-向前缀树中插入字符串word
    void insert(string word) {
        TrieNode* temp = root;
        for(char &c : word){
            if(temp->sons[c] == nullptr){
                temp->sons[c] = new TrieNode(false);
            }
            temp = temp->sons[c];
        }
        if(temp!=root){temp->hasval = true;}
    }

    //-如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false
    bool search(string word) {
        TrieNode* temp = root;
        for(char &c : word){
            if(temp->sons[c] == nullptr){
                return false;
            }
            temp = temp->sons[c];
        }
        return temp->hasval;
    }

    //-如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(char &c : prefix){
            if(temp->sons[c] == nullptr){
                return false;
            }
            temp = temp->sons[c];
        }
        return true;
    }
};