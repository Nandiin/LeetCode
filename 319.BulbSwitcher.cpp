//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(319)
        int bulbSwitch(int n) {
            return sqrt(n);
        };
SOLUTION_END

TEST_BEGIN(319)
    void test(int n, int expected) {
        EXPECT_EQ(Solution().bulbSwitch(n), expected);
    }
TEST_END

MYTEST_F(319, Example) {
    test(3, 1);
}

MYTEST_F(319, Case1) {
    test(7, 2);
}

MYTEST_F(319, Case2) {
    test(10000000, 3162);
}
