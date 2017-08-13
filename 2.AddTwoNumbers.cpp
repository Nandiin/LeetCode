#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(2)
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            bool carryOver = false;
            auto p1 = l1;
            auto p2 = l2;
            ListNode* prev = nullptr;
            auto one = new ListNode(1);
            auto p = l1;
            while (nullptr != p1 && nullptr != p2) {
                auto res = (carryOver ? 1 : 0) + p1->val + p2->val;
                carryOver = res > 9;
                if (carryOver) res -= 10;
                p1->val = res;
                prev = p1;
                p1 = p1->next;
                p2 = p2->next;;
            }
            auto remaining = nullptr != p1 ? p1 : p2;
            if (carryOver) remaining = nullptr == remaining ? one : addTwoNumbers(remaining, one);
            prev->next = remaining;
            return l1;
        }
SOLUTION_END

TEST_BEGIN(2)
    void test(const vector<int>& v1, const vector<int>& v2, const vector<int>& expected) {
        ListNode *l1, *l2;
        buildList(v1, l1);
        buildList(v2, l2);
        vector<int> output;
        buildVector(Solution().addTwoNumbers(l1, l2), output);
        EXPECT_EQ(output, expected);
    }
TEST_END

MYTEST_F(2, Example) {
    test({2, 4, 3}, {5, 6, 4}, {7, 0, 8});
}

MYTEST_F(2, LeadingCarryOver) {
    test({5}, {5}, {0, 1});
}

MYTEST_F(2, Case1) {
    test({9, 8}, {1}, {0, 9});
}

MYTEST_F(2, Case2) {
    test({1}, {9, 9}, {0, 0, 1});
}
