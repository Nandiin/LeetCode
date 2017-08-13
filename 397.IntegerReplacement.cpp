#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(397)
        int integerReplacement(int n) {
            long ln = n;
            auto count = 0;
            while (ln > 1) {
                if (ln == 3) {
                    count += 2;
                    break;
                } else if (ln % 2 == 0) {
                    ln /= 2;
                } else if ((ln + 1) / 2 % 2 == 0) {
                    ln++;
                } else {
                    ln--;
                }
                count ++;
            }
            return count;
        }
SOLUTION_END

TEST_BEGIN(397)
    void test(const int input, int expected) {
        EXPECT_EQ(Solution().integerReplacement(input), expected);
    }
TEST_END

MYTEST_F(397, Example1) {
    test(8, 3);
}

MYTEST_F(397, Case1) {
    test(2147483647, 32);
}

MYTEST_F(397, Case2) {
    test(3, 2);
}

MYTEST_F(397, Case3) {
    test(6, 3);
}
