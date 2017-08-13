
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(572)
        bool isSubtree(TreeNode* s, TreeNode* t) {
            auto d = depth(t, [](TreeNode*, int){});
            auto ans = false;
            depth(s, [d, &ans, this, t](TreeNode* node, int depth) {
                if (d != depth) return;
                ans |= isSame(t, node);
            });
            return ans;
        }

    private:
        bool isSame(TreeNode* s, TreeNode* t) {
            if (nullptr == s && nullptr == t) return true;
            if (nullptr != s && nullptr != t) return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);
            return false;
        }
        int depth(TreeNode* root, const std::function<void(TreeNode*, int)>& visit) {
            if (nullptr == root) return 0;
            auto dl = depth(root->left, visit);
            auto dr = depth(root->right, visit);
            auto d = 1 + std::max(dl, dr);
            visit(root, d);
            return d;
        }
SOLUTION_END

TEST_BEGIN(572)
    void test(const vector<string>& inputS, const vector<string>& inputT, bool expected) {
        TreeNode* rootS;
        TreeNode* rootT;
        buildBST(inputS, rootS);
        buildBST(inputT, rootT);
        EXPECT_EQ(Solution().isSubtree(rootS, rootT), expected);

    }
TEST_END

MYTEST_F(572, Example1) {
    test({"3", "4", "5", "1", "2"}, {"4", "1", "2"}, true);
}

MYTEST_F(572, Example2) {
    test({"3", "4", "5", "1", "2", "#", "#", "#", "#", "0"}, {"4", "1", "2"}, false);
}

MYTEST_F(572, Case1) {
    test({"1", "1"}, {"1"}, true);
}

MYTEST_F(572, Case2) {
    test({"1", "#", "1", "#", "1", "#", "1", "#", "1", "#", "1", "#", "1", "#", "1", "#", "1", "#", "1", "#", "1", "2"},
         {"1", "#", "1", "#", "1", "#", "1", "#", "1", "#", "1", "2"}, true);
}


