//
// Created by Nandiin Borjigin on 12/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(151)

        void reverseWords(string &s) {
            while (' ' == s.back()) s.pop_back();
            while (' ' == s.front()) s = s.substr(1);
            if (s. empty()) return;
            s = "|" + s;
            unsigned long pos = 0;
            unsigned long insertPos = 0;
            while ('|' != s.back()) {
                char back = s.back();
                s.pop_back();
                if (' ' == back) {
                    while(' ' == s.back()) s.pop_back();
                    s.insert(pos, 1, back);
                    insertPos = ++pos;
                } else {
                    s.insert(insertPos, 1, back);
                    ++pos;
                }
            }
            s.pop_back();
        }

SOLUTION_END
TEST_BEGIN(151)
    void test(string input, string expected) {
        Solution().reverseWords(input);
        EXPECT_EQ(input, expected);
    }
TEST_END

MYTEST_F(151, Example) {
    test("the sky is blue", "blue is sky the");
}

MYTEST_F(151, HandlesTrailingWhiteSpaces) {
    test(" ", "");
}

MYTEST_F(151, HandlesLeadingWhiteSpaces) {
    test(" 1", "1");
}

MYTEST_F(151, HandlesMultipleSpaces) {
    test("a  b", "b a");
}
