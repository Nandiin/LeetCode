//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(523)
        bool checkSubarraySum(vector<int>& nums, int k) {
            if (nums.size() < 2) return false;
            if (k == 0) {
                for (auto num : nums) { if (num != 0) return false; }
                return true;
            }
            return backtracking(nums, 0, k);
        }

    private:

        bool backtracking(const vector<int>& nums, int start, int k) {
            if (start > nums.size() - 2) return false;
            int sum = nums[start] + nums[start + 1];
            int i = start + 2;
            while (i < nums.size() && sum % k != 0) {
                sum += nums[i];
                i++;
            }
            if (sum % k == 0) return true;
            return backtracking(nums, start + 1, k);
        }
SOLUTION_END

TEST_BEGIN(523)
    void test(const vector<int>& nums, int k, bool expected) {
        auto nums_ = nums;
        EXPECT_EQ(Solution().checkSubarraySum(nums_, k), expected);
    }
TEST_END

MYTEST_F(523, Example) {
    test({23, 2, 4, 6, 7}, 6, true);
}

MYTEST_F(523, Case2) {
    test({23, 2, 6, 4, 7}, 6, true);
}

MYTEST_F(523, Case3) {
    test({1, 2, 3}, 6, true);
}


