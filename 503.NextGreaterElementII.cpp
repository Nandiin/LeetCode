//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(503)
        vector<int> nextGreaterElements(const vector<int>& nums) {
            vector<int> ret(nums.size(), -1);
            stack<int> indices;
            for (auto i = 0; i < nums.size() * 2; ++i) {
                auto ii = i % nums.size();
                while (!indices.empty() && nums[ii] > nums[indices.top()]) {
                    ret[indices.top()] = nums[ii];
                    indices.pop();
                }
                indices.push(ii);
            }
            return ret;
        }
SOLUTION_END
TEST_BEGIN(503)
    void test(const initializer_list<int>& input, const vector<int>& expected) {
        EXPECT_EQ(Solution().nextGreaterElements(input), expected);
    }
TEST_END

MYTEST_F(503, Example) {
    test({1, 2, 1}, {2, -1, 2});
}