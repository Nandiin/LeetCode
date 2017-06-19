//
// Created by Nandiin Borjigin on 14/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"


namespace _173 {
    class Solution {};
    class BSTIterator {
    public:
        BSTIterator(TreeNode* root) {
            while(nullptr != root) {
                s.push(root);
                root = root->left;
            }
        }
        bool hasNext() {
            return !s.empty();
        }
        int next() {
            auto tmp = s.top();
            s.pop();
            auto p = tmp->right;
            while(nullptr != p) {
                s.push(p);
                p = p->left;
            }
            return tmp->val;
        }

    private:
        stack<TreeNode*> s;
    };
}

TEST_BEGIN(173)
    void test(vector<int> input) {
        TreeNode* root = nullptr;
        for (auto num : input) insert(root, num);
        auto it = _173::BSTIterator(root);
        vector<int> output;
        vector<int> sorted(input);
        std::sort(sorted.begin(), sorted.end());
        while (it.hasNext()) output.push_back(it.next());
        EXPECT_EQ(output, sorted);

    }

private:
    void insert(TreeNode*& root, int val) {
        if (nullptr == root) root = new TreeNode(val);
        else if (val < root->val) insert(root->left, val);
        else if (val > root->val) insert(root->right, val);
    }
TEST_END

MYTEST_F(173, Example) {
    test(vector<int>({ 4, 2, 6, 1, 3, 5, 7}));
}