//
// Created by Nandiin Borjigin on 13/04/2017.
//
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(203)
        ListNode* removeElements(ListNode *head, int val) {
            while (nullptr != head && val == head->val) {
                head = head->next;
            }
            if (nullptr == head) return nullptr;
            auto p = head;
            while (nullptr != p->next) {
                if (val == p->next->val) p->next = p->next->next;
                else p = p->next;
            }
            return head;
        }
SOLUTION_END
TEST_BEGIN(203)
    void test(vector<int> input, int val, vector<int> expected) {
        ListNode* head = nullptr;
        ListNode* expectedList = nullptr;
        buildList(input, head);
        buildList(expected, expectedList);
        auto output = Solution().removeElements(head, val);
        EXPECT_PRED2(equal, output, expectedList);
    }

private:
    static bool equal(ListNode* lhs, ListNode* rhs) {
        if (nullptr == lhs) return nullptr == rhs;
        else if (nullptr == rhs) return false;
        else return (lhs->val == rhs->val) && equal(lhs->next, rhs->next);
    }

TEST_END

MYTEST_F(203, Example) {
    vector<int> input({ 1, 2, 6, 3, 4, 5, 6 });
    vector<int> expected({ 1, 2, 3, 4, 5 });
    test(input, 6, expected);
}