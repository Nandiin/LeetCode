
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(53)
        int maxSubArray(vector<int>& nums) {
            int maxSofar = 0;
            int maxCurr = 0;
            for (int i = 0; i < nums.size(); ++i) {
                maxCurr = std::max(0, maxCurr + nums[i]);
                maxSofar = std::max(maxSofar, maxCurr);
            }
            return maxSofar;
        }

SOLUTION_END

TEST_BEGIN(53)
    void test(const intlist& list, int expected) {
        vector<int> input(list);
        EXPECT_EQ(Solution().maxSubArray(input), expected);
    }
TEST_END


MYTEST_F(53, Case1) {
    test({-2,1,-3,4,-1,2,1,-5,4}, 6);
}