//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(593)
        bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
            auto aIndex = findRightAngle(p1, p2, p3);
            if (aIndex == 3) return false;
            vector<int> temp;
            switch (aIndex) {
                case 1:
                    temp = p2;
                    p2 = p1;
                    p1 = temp;
                    break;
                case 2:
                    temp = p3;
                    p3 = p1;
                    p1 = temp;
                    break;
                default:
                    break;
            }
            if (!isRightAngle(p2, p4, p3)) return false;

            return (abs(p2[1] - p4[1]) == abs(p3[0] - p4[0])) && (abs(p2[1] - p1[1]) == abs(p3[0] - p1[0]));
        }
    private:
        size_t findRightAngle(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
            if (isRightAngle(a, b, c)) return 1;
            if (isRightAngle(b, a, c)) return 0;
            if (isRightAngle(a, c, b)) return 2;
            return 3;
        }
        bool isRightAngle(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
            auto v1x = b[0] - a[0];
            auto v1y = b[1] - a[1];
            if (v1x == 0 && v1y == 0) return false;
            auto v2x = c[0] - b[0];
            auto v2y = c[1] - b[1];
            if (v2x == 0 && v2y == 0) return false;
            return v1x * v2x + v1y * v2y == 0;
        }

SOLUTION_END

TEST_BEGIN(593)
    void test(const vector<int>& points, bool expected) {
        vector<int> a = { points[0], points[1] };
        vector<int> b = { points[2], points[3] };
        vector<int> c = { points[4], points[5] };
        vector<int> d = { points[6], points[7] };
        EXPECT_EQ(Solution().validSquare(a, b, c, d), expected);
    }

TEST_END

MYTEST_F(593, Example) {
    test({0, 0, 1, 1, 1, 0, 0, 1}, true);
}

MYTEST_F(593, SinglePoint) {
    test(vector<int>(8, 3), false);
}

