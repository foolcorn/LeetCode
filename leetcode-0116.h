#include "utils.h"
// * 填充next指针，将二叉树的每一层节点连起来
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){return nullptr;}
        root->next = nullptr;
        traceback(root->left,root->right);
        return root;
    }
    void traceback(Node* left,Node* right){
        if(left == nullptr&&right == nullptr){
            return;
        }
        left->next = right;
        right->next = nullptr;
        traceback(left->left,left->right);
        traceback(left->right,right->left);
        traceback(right->left,right->right);
    }
};
