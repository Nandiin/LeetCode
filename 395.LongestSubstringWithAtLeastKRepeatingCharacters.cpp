
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(395)
        int longestSubstring(string s, int k) {
            if (s.length() < k) return 0;
            vector<int> freq(26, 0);
            for (auto c: s) {
                freq[c - 'a']++;
            }
            vector<size_t> splitPos;
            for (char i = 0; i < 26; ++i) {
                if (freq[i] > 0 && freq[i] < k) {
                    split(s, 'a' + i, splitPos);
                }
            }
            if (splitPos.empty()) return static_cast<int>(s.length());
            std::sort(splitPos.begin(), splitPos.end());
            splitPos.push_back(s.length());
            size_t start = 0;
            int max = 0;
            for (auto pos : splitPos) {
                max = std::max(max, longestSubstring(s.substr(start, pos - start), k));
                start = pos + 1;
            }
            return max;
        }

    private:
        void split(const string& s, char c, vector<size_t>& v) {
            auto pos = s.find(c);
            while (pos != string::npos) {
                v.push_back(pos);
                pos = s.find(c, pos + 1);
            }
        }
SOLUTION_END

TEST_BEGIN(395)
    void test(const string& s, int k, int expected) {
        EXPECT_EQ(Solution().longestSubstring(s, k), expected);
    }
TEST_END

MYTEST_F(395, Example1) {
    test("aaabb", 3, 3);
}

MYTEST_F(395, Example2) {
    test("ababb", 2, 5);
}

MYTEST_F(395, Case1) {
    test("bbaaacbd", 3, 3);
}


