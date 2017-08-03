#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(168)
        string convertToTitle(int n) {
            if (n == 0) return "";
            n -= 1;
            string ret = convertToTitle(n / 26);
            ret.push_back('A' + (char)(n % 26));
            return ret;
        }
SOLUTION_END

TEST_BEGIN(168)
    void test(int n, const string& expected) {
        EXPECT_EQ(Solution().convertToTitle(n), expected);
    }
TEST_END

MYTEST_F(168, Case1) {
    test(27, "AA");
}