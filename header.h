//
// Created by Nandiin Borjigin on 17/04/2017.
//

#ifndef LEETCODE_HEADER2_H
#define LEETCODE_HEADER2_H

#include <vector>
#include <string>
#include <stack>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>

using std::vector;
using std::string;
using std::pair;
using std::initializer_list;
using std::make_pair;
using std::stack;
using std::set;
using std::unordered_set;
using std::unordered_map;
using std::map;
using std::queue;

typedef initializer_list<int> intlist;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


inline void buildList(const vector<int>& vec, ListNode*& head) {
    auto p = &head;
    for (auto num : vec) {
        *p = new ListNode(num);
        p = &((*p)->next);
    }
}

inline void buildVector(ListNode* head, vector<int>& vec) {
    vec.clear();
    while (nullptr != head) {
        vec.push_back(head->val);
        head = head->next;
    }
}

#define SOLUTION_BEGIN(no) namespace _##no { class Solution { public:
#define SOLUTION_END };}
#define TEST_BEGIN(num) class Test##num : public ::testing::Test { public: typedef _##num::Solution Solution;
#define TEST_END };
#define MYTEST_F(num, name) TEST_F(Test##num, name)

#endif //LEETCODE_HEADER2_H
