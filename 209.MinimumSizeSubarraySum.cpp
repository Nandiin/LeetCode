//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(209)
        int minSubArrayLen(int s, vector<int>& nums) {
            auto start = 0;
            auto end = 0;
            auto sum = 0;
            auto minLen = (int)nums.size();

            while (end < nums.size()) {
                sum += nums[end];
                while (sum >= s) {
                    minLen = std::min(minLen, end - start + 1);
                    if (sum - nums[start] < s) break;
                    sum -= nums[start];
                    start++;
                }
                end++;
            }

            return sum >= s ? minLen : 0;
        };

    private:

    
SOLUTION_END

TEST_BEGIN(209)
    void test(int s, const vector<int>& nums, int expected) {
        auto nums_ = nums;
        EXPECT_EQ(Solution().minSubArrayLen(s, nums_), expected);
    }
TEST_END

MYTEST_F(209, Example) {
    test(7, {2,3,1,2,4,3}, 2);
}

MYTEST_F(209, Case1) {
    test(11, {1,2,3,4,5}, 3);
}

MYTEST_F(209, Case2) {
    test(15, {5,1,3,5,10,7,4,9,2,8}, 2);
}

MYTEST_F(209, Case3) {
    test(5, {2,3,1,1,1,1,1}, 2);
}
