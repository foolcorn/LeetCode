#include "utils.h"
// *给定词根列表dictionary，将sentece里的所有单词都替换成最短词根（如果有）
struct TrieNode{
    bool hasval;
    vector<TrieNode*> treelist;
    TrieNode(bool sign) : hasval(sign) {
        treelist.resize(26,nullptr);
    }
};
class TrieTree{
private:
    TrieNode * root;
    TrieTree(){
        root = new TrieNode(false);
    }
    void addWord(string word){
        TrieNode * temp = root;
        for(int i = 0;i<word.size();i++){
            int cindex = word[i]-'a';
            if(temp->treelist[cindex]==nullptr){
                temp->treelist[cindex] = new TrieNode(false);
            }
            temp = temp->treelist[cindex];
        }
        temp.hasval = true;
    }
    string returnRoot(string word){
        TrieNode * temp = root;
        for(int i = 0;i<word.size();++i){
            int cindex = word[i]-'a';
            temp = temp->treelist[cindex];
            if(temp == nullptr){
                return word;
            }
            if(temp->hasval){
                return word.substr(0,i+1);
            }
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieTree trie;
        for(string & ele:dictionary){
            trie.addWord(ele);
        }
        string str = sentence;
        int index = (int)str.find(' ');
        string res;
        while(index != -1){
            string temp = str.substr(0,index);
            res += trie.returnRoot(temp)+" ";
            str = str.substr(index+1);
            index = (int)str.find(' ');
        }
        string temp = str.substr(0,index);
        res += trie.returnRoot(temp);
        return res;
    }
};