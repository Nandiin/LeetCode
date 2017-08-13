
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(114)
        void flatten(TreeNode* root) {
            if (nullptr == root) return;
            stack<TreeNode*> s;
            s.push(root);
            TreeNode* prev = nullptr;
            while (!s.empty()) {
                auto node = s.top();
                s.pop();
                if (nullptr != node->right) s.push(node->right);
                flatten(node->left);
                node->right = node->left;
                node->left = nullptr;
                if (nullptr != prev) prev->right = node;
                prev = node;
                while (nullptr != prev->right) {
                    prev = prev->right;
                }
            }
        }
SOLUTION_END

TEST_BEGIN(114)
    void test(const vector<string>& input, const vector<int>& expected) {
        TreeNode* root;
        buildBST(input, root);
        Solution().flatten(root);
        vector<int> output;
        while(nullptr != root) {
            if (nullptr != root->left) GTEST_FATAL_FAILURE_("Should not have any left child");
            output.push_back(root->val);
            root = root->right;
        }
        EXPECT_EQ(output, expected);
    }
TEST_END

MYTEST_F(114, Example) {
    test({"1", "2", "5", "3", "4", "#", "6"}, {1, 2, 3, 4, 5, 6});
}

