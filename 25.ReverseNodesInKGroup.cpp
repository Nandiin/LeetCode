#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(25)
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* dummy = new ListNode(0);
            ListNode* prev = dummy;
            ListNode* tail = prev;
            dummy->next = head;
            while (true) {
                int i = k;
                while (i-- > 0 && nullptr != tail) tail = tail->next;
                if (nullptr == tail) break;

                head = prev->next;

                while (prev->next != tail) {
                    auto tmp = prev->next;
                    prev->next = tmp->next;
                    tmp->next = tail->next;
                    tail->next = tmp;
                }

                prev = tail = head;
            }

            return dummy->next;
        }
SOLUTION_END

TEST_BEGIN(25)
    void test(const intlist& input, int k) {
        vector<int> inputVec(input);
        vector<int> expected(input);
        auto i = 0;
        while (i + k - 1 < input.size()) {
            std::reverse(expected.begin() + i, expected.begin() + i + k);
            i += k;
        }
        ListNode* head;
        buildList(inputVec, head);
        auto output = Solution().reverseKGroup(head, k);
        vector<int> outputVec;
        buildVector(output, outputVec);
        EXPECT_EQ(outputVec, expected);

    }
TEST_END

MYTEST_F(25, Case1) {
    test({ 1, 2, 3, 4, 5 }, 2);
    test({ 1, 2, 3, 4, 5 }, 3);
}