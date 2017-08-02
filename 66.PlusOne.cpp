//
// Created by Nandiin Borjigin on 12/04/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(66)
        vector<int> plusOne(vector<int>& digits) {
            int pos = digits.size() - 1;
            auto carry = false;
            do {
                carry = digits[pos] == 9;
                digits[pos] = (digits[pos] + 1) % 10;
                pos--;
            } while (carry && pos >= 0);
            if (carry) digits.insert(digits.begin(), 1);
            return digits;
        }
SOLUTION_END

TEST_BEGIN(66)
    void test(const vector<int>& nums_, const vector<int>& expected) {
        auto nums = nums_;
        EXPECT_EQ(Solution().plusOne(nums), expected);
    }
TEST_END

MYTEST_F(66, Case1) {
    test({2, 3, 1, 1, 4}, {2, 3, 1, 1, 5});
}

MYTEST_F(66, HandlesCarry) {
    test({ 9 }, {1, 0});
}


