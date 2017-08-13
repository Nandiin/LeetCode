
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(18)
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            unordered_map<int, vector<pair<int, int>>> twoSums;
            vector<vector<int>> ret;
            for (auto i = 0; i < nums.size(); ++i) {
                for (auto j = i + 1; j < nums.size(); ++j) {
                    twoSums[nums[i] + nums[j]].emplace_back(i, j);
                }
            }

            for (auto& k : twoSums) {
                int remainder = target - k.first;
                if (twoSums.find(remainder) == twoSums.end()) continue;
                auto anotherTwoSum = twoSums[remainder];
                for (auto& pair: k.second) {
                    for (auto& anotherPair: anotherTwoSum) {
                        if (pair.first == anotherPair.first || pair.first == anotherPair.second ||
                            pair.second == anotherPair.first || pair.second == anotherPair.second)
                            continue;
                        auto candidate = vector<int>{nums[pair.first], nums[pair.second], nums[anotherPair.first], nums[anotherPair.second]};
                        std::sort(candidate.begin(), candidate.end());
                        ret.push_back(candidate);
                    }
                }
            }

            auto sortingFunc = [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
                if (lhs[0] < rhs[0]) return true;
                else if (lhs[0] == rhs[0]) {
                    if (lhs[1] < rhs[1]) return true;
                    else if (lhs[1] == rhs[1]) {
                        if (lhs[2] < rhs[2]) return true;
                        else if (lhs[2] == rhs[2]) return lhs[3] < rhs[3];
                    }
                }
                return false;
            };

            std::sort(ret.begin(), ret.end(), sortingFunc);

            auto it = std::unique (ret.begin(), ret.end());

            ret.resize(static_cast<unsigned long>(std::distance(ret.begin(), it)));

            return ret;
        }
SOLUTION_END

TEST_BEGIN(18)
    void test(const vector<int>& nums, int target, const vector<vector<int>>& expected) {
        auto nums_ = nums;
        auto output = Solution().fourSum(nums_, target);
        EXPECT_EQ(output.size(), expected.size());

        auto expected_ = expected;
        auto sortingFunc = [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
            auto lhs_ = lhs;
            auto rhs_ = rhs;
            std::sort(lhs_.begin(), lhs_.end());
            std::sort(rhs_.begin(), rhs_.end());
            if (lhs_[0] < rhs_[0]) return true;
            else if (lhs_[0] == rhs_[0]) {
                if (lhs_[1] < rhs_[1]) return true;
                else if (lhs_[1] == rhs_[1]) {
                    if (lhs_[2] < rhs_[2]) return true;
                    else if (lhs_[2] == rhs_[2]) return lhs_[3] < rhs_[3];
                }
            }
            return false;
        };
        std::sort(expected_.begin(), expected_.end(), sortingFunc);
        std::sort(output.begin(), output.end(), sortingFunc);

        for (auto i = 0; i < expected_.size(); ++i) {
            EXPECT_THAT(output[i], ::testing::UnorderedElementsAreArray(expected_[i]));
        }

    }
TEST_END


MYTEST_F(18, Example) {
    test({1, 0, -1, 0, -2, 2}, 0, { {-1, 0, 0, 1}, {-2, -1, 1, 2}, {-2, 0, 0, 2} });
}

