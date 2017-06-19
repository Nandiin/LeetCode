
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(198)
        int rob(vector<int>& nums) {
            if (nums.empty()) return 0;
            int rob = nums[0];
            int notRob = 0;
            int max = rob;

            for (auto i = 1; i < nums.size(); ++i) {
                int tmpNotRob = notRob;
                int tmpRob = rob;
                rob = nums[i] + tmpNotRob;
                notRob = std::max(tmpNotRob, tmpRob);
                max = std::max(rob, notRob);
            }

            return max;
        }
SOLUTION_END

TEST_BEGIN(198)
    void test(const intlist& input, int expected) {
        vector<int> inputVec(input);
        EXPECT_EQ(Solution().rob(inputVec), expected);
    }
TEST_END

MYTEST_F(198, Case1) {
    test({1}, 1);
}

MYTEST_F(198, Case2) {
    test({1, 2}, 2);
}

MYTEST_F(198, Case3) {
    test({2, 1}, 2);
}

MYTEST_F(198, Case4) {
    test({1, 3, 2}, 3);
}

MYTEST_F(198, Case5) {
    test({1, 3, 3}, 4);
}

MYTEST_F(198, Case6) {
    test({1, 3, 4, 3}, 6);
}

MYTEST_F(198, Case7) {
    test({2, 1, 1, 5}, 7);
}
