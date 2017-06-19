#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(33)
        int search(vector<int>& nums, int target) {
            if (nums.empty()) return -1;
            return advancedBinarySearch(nums, 0, nums.size() - 1, target);
        }

    private:
        int advancedBinarySearch(const vector<int>& nums, int begin, int end, int target) {
            if (begin > end) return -1;
            if (begin == end) return target == nums[begin] ? begin : -1;

            int mid = (begin + end) / 2;

            if (target == nums[mid]) return mid;
            else if (target == nums[begin]) return begin;
            else if (target == nums[end]) return end;

            if (nums[begin] < nums[mid]) {
                // left half is sorted
                if (target > nums[begin] && target < nums[mid]) {
                    // target is in it
                    return binarySearch(nums, begin, mid - 1, target);
                } else {
                    return advancedBinarySearch(nums, mid + 1, end, target);
                }
            } else if (nums[mid] < nums[end]) {
                // right half is sorted
                if (target > nums[mid] && target < nums[end]) {
                    // target is in it
                    return binarySearch(nums, mid + 1, end, target);
                } else {
                    return advancedBinarySearch(nums, begin, mid - 1, target);
                }
            } else {
                // mid == pivot
                if (target > nums[end]) {
                    // target is in left half
                    return binarySearch(nums, begin, mid - 1, target);
                } else {
                    return binarySearch(nums, mid + 1, end, target);
                }
            }
        }

        int binarySearch(const vector<int>& nums, int begin, int end, int target) {
            if (begin > end) return -1;
            if (begin == end) return target == nums[begin] ? begin : -1;
            int mid = (begin + end) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) return binarySearch(nums, begin, mid - 1, target);
            else return binarySearch(nums, mid + 1, end, target);
        }
SOLUTION_END

TEST_BEGIN(33)
    void test(const initializer_list<int>& input, int target, int expected) {
        vector<int> inputVec(input);
        EXPECT_EQ(Solution().search(inputVec, target), expected);
    }
TEST_END


MYTEST_F(33, HandlesEmptyInput) {
    test({}, 4, -1);
}

MYTEST_F(33, HandlesZeroPivotInEvenElements) {
    auto localTest = [&](int target, int expected) {
        test({0, 1, 2, 4}, target, expected);
    };
    localTest(0, 0);
    localTest(4, 3);
    localTest(1, 1);
    localTest(3, -1);
}

MYTEST_F(33, HandlesZeroPivotInOddElements) {
    auto localTest = [&](int target, int expected) {
        test({0, 1, 2, 4, 5}, target, expected);
    };
    localTest(0, 0);
    localTest(5, 4);
    localTest(1, 1);
    localTest(3, -1);
    localTest(2, 2);
}


MYTEST_F(33, Case1) {
    test({4, 5, 6, 7, 0, 1, 2}, 4, 0);
}

MYTEST_F(33, Case2) {
    test({3, 5, 1}, 1, 2);
}
