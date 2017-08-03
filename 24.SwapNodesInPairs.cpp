//
// Created by Nandiin Borjigin on 17/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(24)
        ListNode* swapPairs(ListNode* head) {
            if (nullptr == next(head)) return head;
            ListNode* prev = nullptr;
            auto a = head;
            head = head->next;
            while(nullptr != next(a)) {
                auto b = next(a);
                auto c = next(b);
                //  0 -> 1 -> 2 -> 3
                //  |    |    |    |
                // prev  a    b    c
                if (nullptr != prev) prev->next = b;
                //  0    1 -> 2 -> 3
                //  `---------^
                //  |    |    |    |
                // prev  a    b    c
                prev = a;
                //  0    1 -> 2 -> 3
                //  `---------^
                //       |    |    |
                //       a    b    c
                //      prev
                a->next = c;
                //       ,---------v
                //  0    1    2 -> 3
                //  `---------^
                //       |    |    |
                //       a    b    c
                //      prev
                b->next = a;
                //       ,---------v
                //  0    1 <- 2    3
                //  `---------^
                //       |    |    |
                //       a    b    c
                //      prev
                a = c;
                //       ,---------v
                //  0    1 <- 2    3
                //  `---------^
                //       |    |    |
                //      prev  b    c
                //                 a
                //  0 -> 2 -> 1 -> 3
                //           prev  a
            }
            return head;
        }

    private:
        inline ListNode* next(ListNode* p) {
            return nullptr == p ? nullptr : p->next;
        }
SOLUTION_END

TEST_BEGIN(24)
    void test(const vector<int>& vec, const vector<int>& expected) {
        ListNode* head = nullptr;
        buildList(vec, head);
        ListNode* output = Solution().swapPairs(head);
        vector<int> outputVec;
        buildVector(output, outputVec);
        EXPECT_EQ(outputVec, expected);
    }
TEST_END

MYTEST_F(24, Example) {
    test({1, 2, 3, 4}, {2, 1, 4, 3});
}

MYTEST_F(24, EmptyList) {
    test({}, {});
}

