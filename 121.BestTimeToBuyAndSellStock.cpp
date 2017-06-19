
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(121)
        int maxProfit(vector<int> &prices) {
            int maxSoFar = 0;
            int maxCurr = 0;
            for (auto i = 1; i < prices.size(); ++i) {
                maxCurr = std::max(0, maxCurr + prices[i] - prices[i - 1]);
                maxSoFar = std::max(maxSoFar, maxCurr);
            }
            return maxSoFar;
        }
SOLUTION_END

TEST_BEGIN(121)
    void test(vector<int> input, int expected) {
        EXPECT_EQ(Solution().maxProfit(input), expected);
    }
TEST_END

MYTEST_F(121, Case1) {
    test(vector<int>({ 7, 1, 5, 3, 6, 4 }), 5);
}

MYTEST_F(121, Case2) {
    test(vector<int>({ 7, 6, 4, 3, 1 }), 0);
}