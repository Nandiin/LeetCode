//
// Created by Nandiin Borjigin on 12/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(219)
        bool containsNearbyDuplicate(vector<int> &nums, int k) {
            if (k > nums.size()) k = nums.size();
            set<int> candidates;
            for (int i = 0; i < nums.size(); ++i) {
                if (i > k) candidates.erase(nums[i - k - 1]);
                if (!candidates.insert(nums[i]).second) return true;
            }
            return false;
        }
SOLUTION_END
TEST_BEGIN(219)
    void test(vector<int>& nums, int k, bool expected) {
        EXPECT_EQ(Solution().containsNearbyDuplicate(nums, k), expected);
    }
TEST_END

MYTEST_F(219, HandlesEmptyInput) {
    vector<int> input;
    test(input, 10, false);
}

MYTEST_F(219, Basic) {
    vector<int> input({ 1, 1 });
    test(input, 1, true);
}
