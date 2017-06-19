//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(475)
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            std::sort(houses.begin(), houses.end());
            std::sort(heaters.begin(), heaters.end());
            int prev = -1;
            int next = 0;
            int min = 0;
            for (auto i = 0; i < houses.size(); ++i) {
                while (heaters[next] < houses[i] && next != -1) {
                    if (next < heaters.size() - 1) {
                        next ++;
                    } else {
                        next = -1;
                    }
                    prev ++;
                }
                auto newMin = 0;
                auto distFromPrev = [&]() -> int { return houses[i] - heaters[prev]; };
                auto distToNext = [&]() -> int { return heaters[next] - houses[i]; };
                if (-1 == prev) {
                    newMin = distToNext();
                } else if (-1 == next) {
                    newMin = distFromPrev();
                } else {
                    newMin = std::min(distFromPrev(), distToNext());
                }
                if (newMin > min) min = newMin;
            }
            return min;
        }
SOLUTION_END

TEST_BEGIN(475)
    void test(const vector<int>& houses, const vector<int>& heaters, int expected) {
        auto houses_ = houses;
        auto heaters_ = heaters;
        EXPECT_EQ(Solution().findRadius(houses_, heaters_), expected);
    }
TEST_END

MYTEST_F(475, Example) {
    test({1, 2, 3}, { 2 }, 1);
}

MYTEST_F(475, Case2) {
    test({1, 2, 3, 4}, {1, 4}, 1);
}

MYTEST_F(475, FarRight) {
    test({1, 5}, {10}, 9);
}

MYTEST_F(475, Case3) {
    test({1, 5}, {2}, 3);
}

MYTEST_F(475, Case4) {
    test({1, 2, 3}, {1}, 2);
}

MYTEST_F(475, Case5) {
    test({25921153,510616708}, {771515668,357571490,44788124,927702196,952509530}, 153045218);
}

