#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(23)
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode *head = nullptr;
            ListNode **p = &head;

            for (auto it = lists.begin(); it != lists.end();) {
                if (nullptr == *it) {
                    it = lists.erase(it);
                } else {
                    it++;
                }
            }

            while (lists.size() > 0) {

                if (lists.size() == 1) {
                    *p = lists[0];
                    break;
                }

                auto min = lists.begin();
                for (auto it = min + 1; it != lists.end(); ++it) {
                    if ((*it)->val < (*min)->val) {
                        min = it;
                    }
                }

                *p = *min;
                *min = (*min)->next;
                (*p)->next = nullptr;
                p = &((*p)->next);

                if (nullptr == *min) {
                    lists.erase(min);
                }
            }

            return head;
        }
SOLUTION_END


TEST_BEGIN(23)
    void test(const initializer_list<initializer_list<int>>& input) {
        vector<ListNode*> inputLists;
        vector<int> expected;
        for (auto it = input.begin(); it != input.end(); ++it) {
            vector<int> anInput(*it);
            ListNode* aNode = nullptr;
            buildList(anInput, aNode);
            inputLists.push_back(aNode);
            expected.insert(expected.end(), anInput.begin(), anInput.end());
        }
        std::sort(expected.begin(), expected.end());
        auto output = Solution().mergeKLists(inputLists);
        vector<int> outputVec;
        buildVector(output, outputVec);
        EXPECT_EQ(outputVec, expected);
    }
TEST_END


MYTEST_F(23, HandlesEmptyInput) {
    test({});
}

MYTEST_F(23, HandlesPartialEmptyInput) {
    test({ {}, {1, 2, 3}});
}

MYTEST_F(23, HandlesTwoInputs) {
    test({
             {1, 3, 5},
             {2, 4, 6}
         }
    );
}

MYTEST_F(23, HandlesThreeInputs) {
    test({
             {1, 2, 3},
             {4, 6, 8},
             {5, 7}
         }
    );
}
