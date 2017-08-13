
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(98)
        bool isValidBST(TreeNode* root) {
            int* prev = nullptr;
            return traverse(root, prev);
        }

    private:
        bool traverse(TreeNode* root, int*& prev) {
            if (nullptr == root) return true;
            if (!traverse(root->left, prev)) return false;
            if (nullptr != prev && root->val <= *prev) return false;
            prev = &(root->val);
            return traverse(root->right, prev);
        }
SOLUTION_END

TEST_BEGIN(98)
    void test(const vector<string>& input, bool expected) {
        TreeNode* bst;
        buildBST(input, bst);
        EXPECT_EQ(Solution().isValidBST(bst), expected);
    }
TEST_END


MYTEST_F(98, Example1) {
    test({"2", "1", "3"}, true);
}

MYTEST_F(98, Example2) {
    test({"1", "2", "3"}, false);
}

MYTEST_F(98, Case1) {
    test({"10", "5", "15", "#", "#", "6", "20"}, false);
}

MYTEST_F(98, Case2) {
    test({"1", "#", "1"}, false);
}

