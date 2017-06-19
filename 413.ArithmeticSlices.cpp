//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(413)
        int numberOfArithmeticSlices(vector<int>& A) {
            if (A.size() < 3) return 0;

            int curDelta = A[1] - A[0];
            int curGroupSize = 0;
            auto count = 0;
            for (auto i = 0; i < A.size() - 1; ++i) {
                int delta = A[i + 1] - A[i];
                if (delta == curDelta) curGroupSize++;
                else {
                    if (curGroupSize >= 2) {
                        count += (curGroupSize - 1) * curGroupSize / 2;
                    }
                    curGroupSize = 1;
                    curDelta = delta;
                }
            }

            count += (curGroupSize - 1) * curGroupSize / 2;

            return count;
        }
SOLUTION_END

TEST_BEGIN(413)
    void test(const vector<int>& input, int expected) {
        auto input_ = input;
        EXPECT_EQ(Solution().numberOfArithmeticSlices(input_), expected);
    }
TEST_END

MYTEST_F(413, Example) {
    test({1, 2, 3, 4}, 3);
}
