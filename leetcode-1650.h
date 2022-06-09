#include "utils.h"
// *树节点有父亲节点指针，求两个节点的最近公共祖先

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

class Solution {
public:
    //-思路：其实就相当于判断链表相交了
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *originp = p;
        Node *originq = q;
        while(true){
            p = p->parent;
            q = q->parent;
            if(p == nullptr){
                p = originq;
            }
            if(q == nullptr){
                q = originp;
            }
            cout<<(p?to_string(p->val):"null")<<"    "<<(q?to_string(q->val):"null")<<endl;
            if(p == q){
                return q;
            }
        }
    }
};