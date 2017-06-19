//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(240)
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty() || matrix[0].empty()) return false;
            auto rows = matrix.size();
            auto cols = matrix[0].size();

            return searchMatrix(matrix, target, 0, rows, 0, cols);
        }
    private:
        bool searchMatrix(const vector<vector<int>>& m, int target, int rBegin, int rEnd, int cBegin, int cEnd) {
            if (rBegin == rEnd || cBegin == cEnd) return false;
            if (rBegin == rEnd + 1 && cBegin == cEnd + 1) return m[rBegin][cBegin] == target;

            auto iMid = rBegin + (rEnd - rBegin) / 2;
            auto jMid = cBegin + (cEnd - cBegin) / 2;

            auto lookup = m[iMid][jMid];

            if (lookup == target) {
                return true;
            } else if (lookup > target) {
                return searchMatrix(m, target, rBegin, iMid, cBegin, cEnd) ||
                       searchMatrix(m, target, iMid, rEnd, cBegin, jMid);
            } else {
                return searchMatrix(m, target, iMid + 1, rEnd, cBegin, cEnd) ||
                       searchMatrix(m, target, rBegin, iMid + 1, jMid + 1, cEnd);
            }
        }


SOLUTION_END

TEST_BEGIN(240)
    void test(const vector<vector<int>>& matrix, int target, bool expected) {
        auto matrixCpy = matrix;
        EXPECT_EQ(Solution().searchMatrix(matrixCpy, target), expected);
    }
TEST_END

MYTEST_F(240, Example) {
    auto matrix =
        vector<vector<int>>({ {1,   4,  7, 11, 15},
          {2,   5,  8, 12, 19},
          {3,   6,  9, 16, 22},
          {10, 13, 14, 17, 24},
          {18, 21, 23, 26, 30} });

    test(matrix, 5, true);
    test(matrix, 20, false);
}



