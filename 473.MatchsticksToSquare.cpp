//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(473)
        bool makesquare(vector<int>& nums) {

            if (nums.size() < 4) return false;

            auto total = 0;

            for (auto num : nums) total += num;

            if (total % 4 != 0) return false;

            auto sideLen = total / 4;

            unordered_set<int> used;

            std::sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;});

            return backtracking(nums, used, 4, sideLen, sideLen);
        }

    private:

        bool backtracking(const vector<int>& nums, unordered_set<int>& used, int sideToGo, int lengthToGo, int sideLength) {
            if (sideToGo == 0) return true;

            if (lengthToGo == 0) return backtracking(nums, used, sideToGo - 1, sideLength, sideLength);

            auto previousFaliure = -1;
            for (auto i = 0; i < nums.size(); ++i) {
                if (used.find(i) != used.end()) continue;
                if (previousFaliure > 0 && nums[i] == nums[previousFaliure]) continue;
                if (nums[i] <= lengthToGo) {
                    used.insert(i);
                    if (backtracking(nums, used, sideToGo, lengthToGo - nums[i], sideLength)) return true;
                    used.erase(i);
                    previousFaliure = i;
                }
            }

            return false;
        }
SOLUTION_END

TEST_BEGIN(473)
    void test(const vector<int>& nums, bool expected) {
        auto nums_ = nums;
        EXPECT_EQ(Solution().makesquare(nums_), expected);
    }
TEST_END

MYTEST_F(473, Example) {
    test({1, 1, 2, 2, 2}, true);
}

MYTEST_F(473, Case1) {
    test({3, 3, 3, 3, 4}, false);
}

MYTEST_F(473, Case2) {
    test({3,1,3,3,10,7,10,3,6,9,10,3,7,6,7}, true);
}

MYTEST_F(473, Case3) {
    test({5,5,5,5,16,4,4,4,4,4,3,3,3,3,4}, false);
}

