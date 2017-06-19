#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(328)
        ListNode* oddEvenList(ListNode *head) {
            if (nullptr == head) return nullptr;
            auto evenHead = head->next;
            auto odd = head;
            auto even = evenHead;
            while (even != nullptr) {
                if (nullptr != even->next) {
                    odd->next = even->next;
                    odd = odd->next;
                    even->next = odd->next;
                }
                even = even->next;
            }
            odd->next = evenHead;
            return head;
        }
SOLUTION_END

TEST_BEGIN(328)
    void test(vector<int> input, vector<int> expected) {
        ListNode* head = nullptr;
        buildList(input, head);
        head = Solution().oddEvenList(head);
        vector<int> output;
        buildVector(head, output);
        EXPECT_EQ(output, expected);
    }
TEST_END

MYTEST_F(328, HandleEmpty) {
    test(vector<int>(), vector<int>());
}

MYTEST_F(328, HandleEvenNumberOfInputs) {
    test(vector<int>({1, 2, 3, 4}), vector<int>({ 1, 3, 2, 4}));
}

MYTEST_F(328, HandleOddNumberOfInputs) {
    test(vector<int>({1, 2, 3, 4, 5}), vector<int>({ 1, 3, 5, 2, 4 }));
}
