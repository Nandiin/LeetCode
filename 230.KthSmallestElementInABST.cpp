//
// Created by Nandiin Borjigin on 17/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(230)
        int kthSmallest(TreeNode* root, int k) {
            int target = root->val;
            traverse(root, k, 0, target);
            return target;
        }
    private:
        int traverse(TreeNode* root, int k, int travelled, int& target) {
            if (nullptr == root) return travelled;
            travelled = traverse(root->left, k, travelled, target) + 1;
            if (travelled == k) {
                target = root->val;
                return travelled;
            }
            return traverse(root->right, k, travelled, target);
        }

SOLUTION_END

TEST_BEGIN(230)
    void test(const vector<string>& bst, int k, int expected) {
        TreeNode* root = nullptr;
        buildBST(bst, root);
        EXPECT_EQ(Solution().kthSmallest(root, k), expected);
    }
TEST_END

MYTEST_F(230, Case1) {
    test({ "1" }, 1, 1);
}

MYTEST_F(230, Case2) {
    test({"1", "#", "2"}, 2, 2);
}

MYTEST_F(230, Case3) {
    test({"2", "1", "3"}, 3, 3);
}
