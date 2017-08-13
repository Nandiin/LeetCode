#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(1)
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> valueIndices;
            for (auto i = 0; i < nums.size(); ++i) {
                auto diff = target - nums[i];
                auto it = valueIndices.find(diff);
                if (it != valueIndices.end()) return {i, it->second};
                valueIndices[nums[i]] = i;
            }
            return {0, 0};
        }
SOLUTION_END

TEST_BEGIN(1)
    void test(const vector<int>& input, int target, const vector<int>& expected) {
        auto input_ = input;
        EXPECT_THAT(Solution().twoSum(input_, target), ::testing::UnorderedElementsAreArray(expected));

    }
TEST_END

MYTEST_F(1, Case1) {
    test({3, 2, 4}, 6, {1, 2});
}