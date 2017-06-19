//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(274)
        int hIndex(vector<int>& citations) {
            std::sort(citations.begin(), citations.end());
            int hIndex = 0;
            for (auto i = 1; i <= citations.size(); ++i) {
                auto seperator = citations.size() - i;
                if (citations[seperator  - 1] <= i && citations[seperator] >= i) hIndex = i;
            }
            return hIndex;
        }
SOLUTION_END

TEST_BEGIN(274)
    void test(const vector<int>& citations, int expected) {
        auto citations_ = citations;
        EXPECT_EQ(Solution().hIndex(citations_), expected);
    }
TEST_END

MYTEST_F(274, Example) {
    test({3, 0, 6, 1, 5}, 3);
}

MYTEST_F(274, Case1) {
    test({1, 1}, 1);
}

