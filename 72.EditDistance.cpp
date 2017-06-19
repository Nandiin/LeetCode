
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(72)
        // dynamic programming
        int minDistance(string word1, string word2) {

            vector<int> buffer(word1.length() + 1, 0);

            for (auto i = 0; i <= word1.length(); ++i) {
                buffer[i] = i;
            }

            for (auto j = 1; j <= word2.length(); ++j) {
                auto prev = buffer[0];
                buffer[0] = j;
                for (auto i = 1; i <= word1.length(); ++i) {
                    auto tmp = buffer[i];
                    if (word1[i - 1] == word2[j - 1]) buffer[i] = prev;
                    else buffer[i] = std::min(buffer[i - 1] + 1, std::min(prev + 1, buffer[i] + 1));
                    prev = tmp;
                }
            }

            return buffer.back();
        }
SOLUTION_END

TEST_BEGIN(72)
    void test(string word1, string word2, int expected) {
        EXPECT_EQ(Solution().minDistance(word1, word2), expected);
    }
TEST_END

MYTEST_F(72, Case1) {
    test("red", "bed", 1);
}

MYTEST_F(72, HandlesEmpty) {
    test("", "", 0);
}

MYTEST_F(72, Case2) {
    test("a", "ab", 1);
}

MYTEST_F(72, Case3) {
    test("sea", "eat", 2);
}

MYTEST_F(72, Case4) {
    test("food", "money", 4);
}

MYTEST_F(72, Case5) {
    test("spartan", "part", 3);
}

MYTEST_F(72, Case6) {
    test("plasma", "altruism", 6);
}
