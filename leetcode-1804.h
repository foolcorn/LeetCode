#include "utils.h"
// *实现前缀树2，实现一些新功能
struct TrieNode{
    int count = 0;
    vector<TrieNode*> treelist = vector<TrieNode*>(256,nullptr);
};
class Trie {
private:
    TrieNode *root = new TrieNode;
public:
    Trie() {}
    //-插入字符串
    void insert(string word) {
        TrieNode *temp = root;
        for (char &c : word){
            if(temp->treelist[c] == nullptr){
                temp-> treelist[c] = new TrieNode;
            }
            temp = temp->treelist[c];
        }
        temp->count++;
    }

    //-返回key==word的字符串个数
    int countWordsEqualTo(string word) {
        TrieNode *temp = root;
        for(char &c : word){
            if(temp->treelist[c] == nullptr){
                return 0;
            }
            temp = temp->treelist[c];
        }
        return temp->count;
    }

    //-返回以prefix为前缀的字符串个数
    int countWordsStartingWith(string prefix) {
        TrieNode *temp = root;
        for(char &c : prefix){
            if(temp->treelist[c] == nullptr){
                return 0;
            }
            temp = temp->treelist[c];
        }
        return traceback(temp);
    }
    int traceback(TrieNode* root){
        int res = root->count;
        for(int i = 0;i<root->treelist.size();++i){
            TrieNode* temp = root->treelist[i];
            if(temp!=nullptr){
                res += traceback(temp);
            }
        }
        return res;
    }

    //-删除字符串。
    void erase(string word) {
        TrieNode *temp = root;
        for(char &c : word){
            if(temp->treelist[c] == nullptr){
                return;
            }
            temp = temp->treelist[c];
        }
        temp->count--;
    }
};