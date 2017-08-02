#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(160)
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (nullptr == headA || nullptr == headB) return nullptr;
            auto pA = headA;
            auto pB = headB;
            ListNode* tailA = nullptr;
            ListNode* tailB = nullptr;

            while (pA != pB) {
                if (nullptr == pA->next) {
                    tailA = pA;
                    pA = headB;
                    if (nullptr != tailB && tailA != tailB) return nullptr;
                } else {
                    pA = pA->next;
                }

                if (nullptr == pB->next) {
                    tailB = pB;
                    pB = headA;
                    if (nullptr != tailA && tailA != tailB) return nullptr;
                } else {
                    pB = pB->next;
                }
            }

            return pA;
        }
SOLUTION_END

TEST_BEGIN(160)
    void test(int aLen, int bLen, int cLen) {
        vector<int> a(aLen, 0);
        vector<int> b(bLen, 0);
        vector<int> c(cLen, 0);

        ListNode* headA;
        ListNode* headB;
        ListNode* headC;

        buildList(a, headA);
        buildList(b, headB);
        buildList(c, headC);

        auto tail = [](ListNode* head) -> ListNode* {
            auto p = head;
            while(nullptr != p->next) p = p->next;
            return p;
        };

        ListNode* aTail = tail(headA);
        ListNode* bTail = tail(headB);

        aTail->next = headC;
        bTail->next = headC;

        EXPECT_EQ(Solution().getIntersectionNode(headA, headB), headC);
    }
TEST_END

MYTEST_F(160, Case1) {
    test(2, 3, 3);
}