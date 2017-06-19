//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(257)
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> result;
            traverse(result, "", root);
            return result;
        }
    private:
        void traverse(vector<string>& result, string currentPath, TreeNode* node) {
            if (nullptr == node) return;
            currentPath += std::to_string(node->val);
            if (nullptr == node->left && nullptr == node->right) {
                result.push_back(currentPath);
            } else {
                traverse(result, currentPath + "->", node->left);
                traverse(result, currentPath + "->", node->right);
            }
        }

SOLUTION_END
TEST_BEGIN(257)
    void test(TreeNode* root, const vector<string>& expected) {
        EXPECT_EQ(Solution().binaryTreePaths(root), expected);
    }
TEST_END

MYTEST_F(257, Example) {
    TreeNode root(1);
    TreeNode left(2);
    TreeNode right(3);
    TreeNode leaf(5);
    left.right = &leaf;
    root.left = &left;
    root.right = &right;
    test(&root, {"1->2->5", "1->3"});
}



