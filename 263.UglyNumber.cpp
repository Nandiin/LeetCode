//
// Created by Nandiin Borjigin on 11/04/2017.
//
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(263)
        bool isUgly(int num) {
            if (num == 0) return false;
            else if (num == 1) return true;
            else if (0 == num % 2) return isUgly(num / 2);
            else if (0 == num % 3) return isUgly(num / 3);
            else if (0 == num % 5) return isUgly(num / 5);
            else return false;
        }
SOLUTION_END

TEST_BEGIN(263)
    void test(int value, bool expected) {
        EXPECT_EQ(Solution().isUgly(value), expected);
    }
TEST_END

MYTEST_F(263, Case1) {
    test(6, true);
}

MYTEST_F(263, Case2) {
    test(8, true);
}

MYTEST_F(263, Case3) {
    test(14, false);
}

MYTEST_F(263, ZeroIsNotUgly) {
    test(0, false);
}

