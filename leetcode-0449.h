#include "utils.h"
// *序列化与反序列化BST
class Codec {
public:
    // -序列化BST，先序遍历，不用存nullptr
    string serialize(TreeNode* root) {
        string s;
        tracebackserialize(root,s);
        return s;
    }
    void tracebackserialize(TreeNode* root, string &s){
        if(root == nullptr){
            return;
        }
        s+= to_string(root->val)+",";
        tracebackserialize(root->left,s);
        tracebackserialize(root->right,s);
    }
    // -反序列化BST
    TreeNode* deserialize(string data) {
        deque<int> nodelist;
        while(data.find(',')!=string::npos){
            int index = data.find(',');
            string head = data.substr(0,index);
            if(head!=","){
                nodelist.push_back(stoi(head));
            }
            data = data.substr(index+1);
        }
        return traceback(nodelist,INT_MIN,INT_MAX);
    }
    //-在构造二叉树的过程中,始终框定一个插入界限
    TreeNode* traceback(deque<int> &nodelist, int min, int max){
        //-这个baseclass也记一下
        if(nodelist.empty()){
            return nullptr;
        }
        //-先取当前预备的元素看看是否适合插入
        int value = nodelist.front();
        //-如果当前节点不适合在该位置插入,就递归到下个位置,这个位置就填入nullptr
        if(value>max||value<min){
            return nullptr;
        }
        TreeNode* temp = new TreeNode(value);
        nodelist.pop_front();
        temp->left = traceback(nodelist,min,value);
        temp->right = traceback(nodelist,value,max);
        return temp;
    }
};