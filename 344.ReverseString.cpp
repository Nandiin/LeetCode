//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(344)
        string reverseString(string s) {
            string out = "";
            for (auto i = (int)s.length() - 1; i >= 0; --i) {
                out.push_back(s[i]);
            }
            return out;
        };
SOLUTION_END

TEST_BEGIN(344)
    void test(string input, string expected) {
        EXPECT_EQ(Solution().reverseString(input), expected);
    }
TEST_END

MYTEST_F(344, Example) {
    test("hello", "olleh");
}
