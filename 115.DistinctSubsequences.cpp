//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(115)
        int numDistinct(string s, string t) {
            auto m = t.size();
            auto n = s.size();
            if (m > n) return 0;
            vector<int> path(m + 1, 0);
            path[0] = 1;
            for (size_t j = 1; j <= n; ++j) {
                for (auto i = std::min(j, m); i >= 1; --i) {
                    path[i] = path[i] + (t[i - 1] == s[j - 1] ? path[i - 1] : 0);
                }
            }
            return path[m];
        }
SOLUTION_END

TEST_BEGIN(115)
    void test(const string& s, const string& t, int expected) {
        EXPECT_EQ(Solution().numDistinct(s, t), expected);
    }
TEST_END

MYTEST_F(115, Example) {
    test("rabbbit", "rabbit", 3);
}

MYTEST_F(115, Case2) {
    test("cbabbabbabaca", "caaaa", 5);
}

