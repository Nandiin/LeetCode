
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(655)
        vector<vector<string>> printTree(TreeNode* root) {
            auto h = height(root);
            auto w = (1 << h) - 1;
            vector<vector<string>> ret(h, vector<string>(w, ""));
            traverse(root, ret, 0, w / 2);
            return ret;
        }
    private:
        int height(TreeNode* root) {
            if (nullptr == root) return 0;
            return 1 + std::max(height(root->left), height(root->right));
        }
        void traverse(TreeNode* root, vector<vector<string>>& str, int i, int j) {
            if (nullptr == root) return;
            str[i][j] = std::to_string(root->val);
            auto rh = str.size() - i;
            if (rh == 1) return;
            auto delta = ((1 << rh) - 1) / 4 + 1;
            traverse(root->left, str, i + 1, j - delta);
            traverse(root->right, str, i + 1, j + delta);
        }
SOLUTION_END

TEST_BEGIN(655)
    void test(const vector<string>& input, const vector<vector<string>> expected) {
        TreeNode* root = nullptr;
        buildBST(input, root);
        EXPECT_EQ(Solution().printTree(root), expected);
    }
TEST_END


MYTEST_F(655, Example1) {
    test({"1", "2", "#"}, {{"", "1" , ""}, {"2", "", ""}});
}

MYTEST_F(655, Example2) {
    test({"1", "2", "3", "#", "4"},
         {{"", "", "", "1", "", "", ""},
          {"", "2", "", "", "", "3", ""},
          {"", "", "4", "", "", "", ""}});
}

MYTEST_F(655, Example3) {
    test({"1", "2", "5", "3", "#", "#", "#", "4"},
         {{"",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""},
          {"",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""},
          {"",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""},
          {"4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""}});
}

