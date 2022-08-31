// *包含所有常用头文件
#ifndef LEETCODE_UTILS_H
#define LEETCODE_UTILS_H

#include <iostream>
#include <deque>
#include <random>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <queue> //优先级队列
#include <functional> //标准greater和less
#include <string>
#include <map>
#include <cstddef>
#include <list>
#include <utility>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
template<class T> void print(T t){
    cout<<t<<endl;
}

template <> void print(vector<int> res){
    for(auto& ele:res){
        cout<<ele<<" ";
    }
    cout<<endl;
}
template<>void print(vector<string> res){
    for(auto& ele:res){
        cout<<ele<<" ";
    }
    cout<<endl;
}

#endif //LEETCODE_UTILS_H
