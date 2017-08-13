
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(120)
        int minimumTotal(vector<vector<int>>& triangle) {
            for (auto k = 2; k <= triangle.size(); ++k) {
                auto i = triangle.size() - k;
                for (auto j = 0; j <= i; ++j) {
                    triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                }
            }
            return triangle[0][0];
        }
SOLUTION_END

TEST_BEGIN(120)
    void test(const vector<vector<int>>& input, int expected) {
        auto input_ = input;
        EXPECT_EQ(Solution().minimumTotal(input_), expected);
    }
TEST_END


MYTEST_F(120, Example) {
    test({{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, 11);
}

MYTEST_F(120, Negative) {
    test({{-1},{2, 3},{1, -1, -3}}, -1);
}
