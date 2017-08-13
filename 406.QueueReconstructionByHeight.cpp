
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(406)
        vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {

            if (people.size() < 2) return people;

            auto sortingFunc = [](const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool {
                return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
            };

            std::sort(people.begin(), people.end(), sortingFunc);

            unordered_map<int, int> m;

            for (auto i = 0; i < people.size(); ++i) {
                if (m.find(people[i].first) == m.end()) m[people[i].first] = i;
            }

            for (int j = 0; j <= people.size() - 2; ++j) {
                auto i = people.size() - 2 - j;
                auto firstEqualHeight = m[people[i].first];
                auto precedingEqualHeights = i - firstEqualHeight;
                auto diff = people[i].second - precedingEqualHeights;
                if (diff == 0) continue;
                std::rotate(people.begin() + i, people.begin() + i + 1, people.begin() + i + diff + 1);
            }

            return people;
        }

    private:
        string printDict(const map<int, int>& m) {
            string ret;
            for (auto& p: m) ret += std::to_string(p.first) + " => " + std::to_string(p.second) + "\n";
            printf("\n----------\n");
            printf("%s", ret.c_str());
            return ret;
        }
SOLUTION_END

TEST_BEGIN(406)
    void test(const vector<vector<int>>& input, const vector<vector<int>>& expected) {
        vector<pair<int, int>> input_(input.size());
        vector<pair<int, int>> expected_(expected.size());
        for (auto i = 0; i < input.size(); ++i) {
            input_[i] = std::make_pair(input[i][0], input[i][1]);
            expected_[i] = std::make_pair(expected[i][0], expected[i][1]);
        }
        EXPECT_EQ(Solution().reconstructQueue(input_), expected_);
    }
TEST_END


MYTEST_F(406, Example1) {
    test({{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}}, {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}});
}

MYTEST_F(406, Case1) {
    test({{6, 0},{5, 0},{4, 0},{3, 2},{2, 2},{1, 4}}, {{4, 0},{5, 0},{2, 2},{3, 2},{1, 4},{6, 0}});
}

MYTEST_F(406, Empty) {
    test({}, {});
}
