
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(337)
        int rob(TreeNode* root) {
            int robbed = 0;
            int notRobbed = 0;
            rob(root, robbed, notRobbed);
            return notRobbed;
        }
    private:
        void rob(TreeNode* node, int& parentRobbed, int& parentNotRobbed) {
            if (nullptr == node) {
                parentNotRobbed = 0;
                parentRobbed = 0;
                return;
            }
            auto parentRobbedLeft = 0;
            auto parentNotRobbedLeft = 0;
            auto parentRobbedRight = 0;
            auto parentNotRobbedRight = 0;
            rob(node->left, parentRobbedLeft, parentNotRobbedLeft);
            rob(node->right, parentRobbedRight, parentNotRobbedRight);
            parentNotRobbed = std::max(node->val + parentRobbedLeft + parentRobbedRight, parentNotRobbedLeft + parentNotRobbedRight);
            parentRobbed = parentNotRobbedLeft + parentNotRobbedRight;
        }
SOLUTION_END

TEST_BEGIN(337)
    void test(const vector<string>& input, int expected) {
        TreeNode* root;
        buildBST(input, root);
        EXPECT_EQ(Solution().rob(root), expected);
    }
TEST_END

MYTEST_F(337, Example1) {
    test({"3", "2", "3", "#", "3", "#", "1"}, 7);
}

MYTEST_F(337, Example2) {
    test({"3", "4", "5", "1", "3", "#", "1"}, 9);
}

