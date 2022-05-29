#include "utils.h"
// *二叉树序列化与反序列化
class Codec {
private:
    string res;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        traverse(root);
        //-最后去掉最前面的','
        return res.substr(1);
    }
    void traverse(TreeNode* root){
        //-使用*代替null节点
        if(root == nullptr){
            res += ",*";
            return;
        }
        res += ","+to_string(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    TreeNode* traverseStr(string &s){
        int index = s.find(',');
        //-找不到index的时候,就是只剩一个元素了,要么是null要么就是一个int值,转成节点直接返回
        if(index == -1){
            return s=="*"?nullptr:new TreeNode(stoi(s));
        }
        string first = s.substr(0, index);
        //-如果当前节点是null,直接返回
        if(first == "*"){
            s = s.substr(2);
            return nullptr;
        }
        //-如果不是null,说明当前节点必有左右子树,直接用先序遍历的方法继续处理字符串
        int firstnum = stoi(first);
        TreeNode*temp = new TreeNode(firstnum);
        s = s.substr(index+1);
        temp->left = traverseStr(s);
        temp->right = traverseStr(s);
        return temp;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string temp = data;
        return traverseStr(temp);
    }
};