
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(594)
        int findLHS(vector<int>& nums) {
            if (nums.empty()) return 0;
            unordered_map<int, int> count;
            for (auto num: nums) {
                count[num]++;
            }
            auto lhs = 0;
            for (auto& kv: count) {
                if (count.find(kv.first + 1) == count.end()) continue;
                lhs = std::max(lhs, kv.second + count[kv.first + 1]);
            }
            return lhs;
        }
SOLUTION_END

TEST_BEGIN(594)
    void test(const vector<int>& input, int expected) {
        auto nums = input;
        EXPECT_EQ(Solution().findLHS(nums), expected);
    }
TEST_END

MYTEST_F(594, Example) {
    test({1, 3, 2, 2, 5, 2, 3, 7}, 5);
}

