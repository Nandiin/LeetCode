#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(3)
        int lengthOfLongestSubstring(string s) {
            vector<int> charIndex(256, -1);
            int start = -1;
            int maxLen = 0;
            for (auto i = 0; i < s.size(); ++i) {
                start = std::max(start, charIndex[s[i]]);
                charIndex[s[i]] = i;
                maxLen = std::max(maxLen, i - start);
            }
            return maxLen;
        }
SOLUTION_END

TEST_BEGIN(3)
    void test(const string& input, int expected) {
        auto input_ = input;
        EXPECT_EQ(Solution().lengthOfLongestSubstring(input_), expected);
    }
TEST_END

MYTEST_F(3, Example1) {
    test("abcabcbb", 3);
}

MYTEST_F(3, Example2) {
    test("bbbbb", 1);
}

MYTEST_F(3, Example3) {
    test("pwwkew", 3);
}

MYTEST_F(3, SingleCharacter) {
    test("c", 1);
}

MYTEST_F(3, Case1) {
    test("dvdf", 3);
}

MYTEST_F(3, Case2) {
    test("abba", 2);
}

