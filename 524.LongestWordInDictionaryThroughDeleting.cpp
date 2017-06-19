//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(524)
        string findLongestWord(string s, vector<string>& d) {
            string ans;

            for (auto i = 0; i < d.size(); ++i) {
                auto pj = 0;
                for (auto pi = 0; pi < s.size() && pj < d[i].size(); ++pi) {
                    pj += (s[pi] == d[i][pj] ? 1 : 0);
                }
                if (pj == d[i].size() // string matches
                    && (ans.size() < d[i].size() // longer answer
                        || (ans.size() == d[i].size() && ans > d[i]))) { // same length but smaller lexicographical order
                    ans = d[i];
                }
            }
            return ans;
        }
SOLUTION_END

TEST_BEGIN(524)
    void test(const string& s, const initializer_list<string>& dict, const string& expected) {
        vector<string> dict_ = dict;
        EXPECT_EQ(Solution().findLongestWord(s, dict_), expected);
    }
TEST_END

MYTEST_F(524, Example) {
    test("abpcplea", {"ale","apple","monkey","plea"}, "apple");
}

MYTEST_F(524, Case2) {
    test("abpcplea", {"a", "b", "c"}, "a");
}

MYTEST_F(524, TLE) {
    test("aewfafwafjlwajflwajflwafj",
         {"apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"},
         "ewaf");
}

