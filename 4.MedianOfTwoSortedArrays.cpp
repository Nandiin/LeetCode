
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(4)
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            size1 = nums1.size();
            size2 = nums2.size();
            if (size1 > size2) {
                swap(nums1, nums2);
                size1 = size2;
                size2 = nums2.size();
            }
            return find(nums1, nums2, 0, size1);
        }

    private:
        double find(const vector<int>& nums1, const vector<int>& nums2, size_t imin, size_t imax) {
            auto i = (imin + imax) / 2;
            auto j = (size1 + size2 + 1) / 2 - i;
            if ((i == 0 || nums1[i - 1] <= nums2[j]) && (i == size1 || nums2[j - 1] <= nums1[i])) {
                auto left = (i == 0) ? nums2[j - 1] : (j == 0) ? nums1[i - 1] : std::max(nums1[i - 1], nums2[j - 1]);
                auto right = (i == size1) ? nums2[j] : (j == size2) ? nums1[i] : std::min(nums1[i], nums2[j]);
                return  (size1 + size2) % 2 == 0 ? (left + right) / 2.0 : left;
            } else if (i < size1 && nums1[i] < nums2[j - 1]) {
                return find(nums1, nums2, i + 1, imax);
            } else if (i > 0 && nums1[i - 1] > nums2[j]) {
                return find(nums1, nums2, imin, i - 1);
            }
        }
        size_t size1;
        size_t size2;
SOLUTION_END

TEST_BEGIN(4)
    void test(const intlist& nums1, const intlist& nums2, double expected) {
        vector<int> input1(nums1);
        vector<int> input2(nums2);
        EXPECT_DOUBLE_EQ(Solution().findMedianSortedArrays(input1, input2), expected);
    }
TEST_END


MYTEST_F(4, Case1) {
    test({1, 3}, {2}, 2);
}

MYTEST_F(4, Case2) {
    test({1, 2}, {3, 4}, 2.5);
}

MYTEST_F(4, Case3) {
    test({1, 2}, {2, 3}, 2);
}
