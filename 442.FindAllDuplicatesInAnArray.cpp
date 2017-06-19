//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(442)
        vector<int> findDuplicates(vector<int>& nums) {
            auto ret = vector<int>();
            for (auto i = 0; i < nums.size();) {
                if (nums[i] < 0) {
                    ++i;
                } else if (nums[nums[i] - 1] == -1) {
                    ret.push_back(nums[i]);
                    nums[nums[i] - 1] = -2;
                    ++i;
                } else if (nums[i] - 1 == i) {
                    nums[i] = -1;
                    ++i;
                } else {
                    auto tmp = nums[nums[i] - 1];
                    nums[nums[i] - 1] = -1;
                    nums[i] = tmp;
                }
            }
            return ret;
        }
SOLUTION_END

TEST_BEGIN(442)
    void test(const vector<int>& input, const vector<int>& expected) {
        auto i = input;
        EXPECT_THAT(Solution().findDuplicates(i), ::testing::UnorderedElementsAreArray(expected));
    }
TEST_END

MYTEST_F(442, Example) {
    test({ 4,3,2,7,8,2,3,1 }, {2, 3});
}


MYTEST_F(442, SingleElement) {
    test({ 1 }, {});
}