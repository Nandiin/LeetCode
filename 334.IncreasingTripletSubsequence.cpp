
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(334)
        bool increasingTriplet(vector<int>& nums) {
            if (nums.size() < 3) return false;
            bool findingSecond = true;
            int first = nums[0];
            int second = INT_MAX;
            for (auto i = 1; i < nums.size(); ++i) {
                if (nums[i] <= first) first = nums[i];
                else if (nums[i] <= second) second = nums[i];
                else return true;
            }
            return false;
        }
SOLUTION_END

TEST_BEGIN(334)
    void test(const vector<int>& input, bool expected) {
        auto nums = input;
        EXPECT_EQ(Solution().increasingTriplet(nums), expected);
    }
TEST_END

MYTEST_F(334, Example1) {
    test({1, 2, 3, 4, 5}, true);
}

MYTEST_F(334, Example2) {
    test({5, 4, 3, 2, 1}, false);
}

MYTEST_F(334, Case1) {
    test({2, 5, 3, 4, 5}, true);
}

