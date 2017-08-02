//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(31)
        void nextPermutation(vector<int>& nums) {
            nextPermutation(nums, 0);
        }

    private:
        bool nextPermutation(vector<int>& nums, size_t begin) {

            if (nums.size() < 2) {
                return false;
            }

            if (nums.size() - begin == 2) {
                auto temp = nums[begin];
                nums[begin] = nums[begin + 1];
                nums[begin + 1] = temp;
                return nums[begin] <= nums[begin + 1];
            }

            if (nextPermutation(nums, begin + 1)) {
                auto temp = nums[begin];
                auto pos = insertPos(nums, begin + 1, nums.size(), temp);
                if (pos == nums.size()) {
                    nums.erase(nums.begin() + begin);
                    nums.push_back(temp);
                    return true;
                } else {
                    nums[begin] = nums[pos];
                    nums[pos] = temp;
                    return false;
                }
            }

            return false;
        }

        size_t insertPos(const vector<int>& nums, size_t begin, size_t end, int target) {
            if (begin == end) {
                return begin;
            }

            if (begin == end - 1) {
                return nums[begin] > target ? begin : end;
            }

            size_t mid = begin + (end - begin) / 2;

            if (nums[mid] > target) {
                return insertPos(nums, begin, mid, target);
            } else {
                return insertPos(nums, mid + 1, end, target);
            }
        }

SOLUTION_END
TEST_BEGIN(31)
    void test(const vector<int>& input, const vector<int>& expected) {
        auto input_ = input;
        Solution().nextPermutation(input_);
        EXPECT_EQ(input_, expected);
    }
TEST_END

MYTEST_F(31, Example1) {
    test({1, 2, 3}, {1, 3, 2});
}
MYTEST_F(31, Example2) {
    test({3, 2, 1}, {1, 2, 3});
}
MYTEST_F(31, Example3) {
    test({ 1, 1, 5 }, { 1, 5, 1});
}

MYTEST_F(31, OneDigit) {
    test({1}, {1});
}

MYTEST_F(31, Case1) {
    test({1, 3, 2}, {2, 1, 3});
}

MYTEST_F(31, Case2) {
    test({2, 3, 1}, {3, 1, 2});
}

MYTEST_F(31, IdenticalDIgits) {
    test({5, 1, 1}, {1, 1, 5});
}

MYTEST_F(31, Case3) {
    test({5,4,7,5,3,2}, {5,5,2,3,4,7});
}

