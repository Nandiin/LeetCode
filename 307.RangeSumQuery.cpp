
#include <gtest/gtest.h>
#include "header.h"

namespace _307 {
    class Solution {};
    class NumArray {
    public:
        NumArray(vector<int> nums) {
            buildTree(nums, root, 0, nums.size() - 1);
        }

        void update(int i, int val) {
            update(root, i, val);
        }

        int sumRange(int i, int j) {
            return sumRange(root, i, j);
        }


    private:

        typedef struct SegmentTreeNode {
            size_t start, end;
            int sum;
            SegmentTreeNode* left;
            SegmentTreeNode* right;
            SegmentTreeNode(size_t a, size_t b) : start(a), end(b), sum(0), left(nullptr), right(nullptr) {}
        } *SegmentTree;


        SegmentTree root;

        void buildTree(const vector<int>& nums, SegmentTree& root, size_t start, size_t end) {
            if (start >= nums.size()) return;
            root = new SegmentTreeNode(start, end);
            if (start == end) {
                root->sum = nums[start];
            } else {
                auto mid = (start + end) / 2;
                buildTree(nums, root->left, start, mid);
                buildTree(nums, root->right, mid + 1, end);
                root->sum = root->left->sum + root->right->sum;
            }
        }

        void update(SegmentTree node, int pos, int value) {
            if (nullptr == node) return;
            if (node->start == node->end) {
                node->sum = value;
            } else {
                auto mid = (node->start + node->end) / 2;
                if (pos <= mid) {
                    update(node->left, pos, value);
                } else {
                    update(node->right, pos, value);
                }
                node->sum = node->left->sum + node->right->sum;
            }
        }

        int sumRange(const SegmentTree node, int start, int end) {
            if (nullptr == node) return 0;
            if (node->start == start && node->end == end) {
                return node->sum;
            } else {
                auto mid = (node->start + node->end) / 2;
                if (end <= mid) return sumRange(node->left, start, end);
                else if (start > mid) return sumRange(node->right, start, end);
                else return sumRange(node->left, start, mid) + sumRange(node->right, mid + 1, end);
            }
        }

    };
}


TEST_BEGIN(307)
    enum Operation {
        Update,
        SumRange
    };
    typedef pair<Operation, intlist> Command;
    void test(const intlist &initial, const initializer_list<Command> &operations) {
        _307::NumArray array(initial);
        vector<Command> operationsVec(operations);
        for (auto i = 0; i < operationsVec.size(); ++i) {
            auto operand = vector<int>(operationsVec[i].second);
            switch (operationsVec[i].first) {
                case Update:
                    array.update(operand[0], operand[1]);
                    break;
                case SumRange:
                    EXPECT_EQ(array.sumRange(operand[0], operand[1]), operand[2]);
                    break;
            }
        }
    }
TEST_END

MYTEST_F(307, Example) {
    auto makepair = [](Operation op, intlist list) -> Command {
        return make_pair(op, list);
    };
    test({1, 3, 5},
         {
             makepair(SumRange, {0, 2, 9}),
             makepair(Update, {1, 2}),
             makepair(SumRange, {0, 2, 8})
         }
    );
}

MYTEST_F(307, HandlesEmptyInitialization) {
    test({}, {});
}