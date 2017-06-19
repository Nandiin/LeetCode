//
// Created by Nandiin Borjigin on 17/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(214)
        string shortestPalindrome(string s) {
            string rev(s);
            std::reverse(rev.begin(), rev.end());
            string l = s + "#" + rev;
            vector<size_t> p(l.size() + 1, 0);

            for (size_t i = 1; i < l.size(); ++i) {
                auto j = p[i];
                while (j > 0 && l[i] != l[j]) j = p[j];
                p[i + 1] = j + (l[i] == l[j] ? 1 : 0);
            }

            return rev.substr(0, rev.size() - p.back()) + s;
        }

    private:
        bool isPalindrome(const string& s, const size_t len) {
            if (len < 2) return true;
            for (size_t i = 0, j = len - 1; i < j; ++i, --j) {
                if (s[i] != s[j]) return false;
            }
            return true;
        }
        void buildPalindrome(string& s, string& prefix, const size_t len) {
            if (isPalindrome(s, len)) return;
            prefix.push_back(s[len - 1]);
            buildPalindrome(s, prefix, len - 1);
        }
SOLUTION_END

TEST_BEGIN(214)
    void test(string input, string expected) {
        EXPECT_EQ(Solution().shortestPalindrome(input), expected);
    }
TEST_END


MYTEST_F(214, Case1) {
    test("aacecaaa", "aaacecaaa");
}

MYTEST_F(214, Case2) {
    test("abcd", "dcbabcd");
}

MYTEST_F(214, Case3) {
    test("aabba", "abbaabba");
}

MYTEST_F(214, HandlesEmptyInput) {
    test("", "");
}