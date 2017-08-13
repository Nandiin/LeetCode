#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(447)
        int numberOfBoomerangs(vector<pair<int, int>>& points) {
            unordered_map<int, int> distances;
            auto dist = [](const pair<int, int>& p1, const pair<int, int>& p2) -> int {
                auto v1 = p1.first - p2.first;
                auto v2 = p1.second - p2.second;
                return v1 * v1 + v2 * v2;
            };

            int count = 0;

            for (auto i = 0; i < points.size(); ++i) {
                for (auto j = 0; j < points.size(); ++j) {
                    if (j == i) continue;
                    auto d = dist(points[i], points[j]);
                    if (distances.find(d) != distances.end()) distances[d]++;
                    else distances[d] = 1;
                }
                for (auto& n: distances) {
                    if (n.second < 2) continue;
                    count += n.second * (n.second - 1);
                }
                distances.clear();
            }

            return count;
        }
SOLUTION_END

TEST_BEGIN(447)
    void test(const vector<vector<int>>& input, int expected) {
        vector<pair<int, int>> points;
        for (auto& p : input) {
            points.push_back(std::make_pair(p[0], p[1]));
        }
        EXPECT_EQ(Solution().numberOfBoomerangs(points), expected);
    }
TEST_END

MYTEST_F(447, Example) {
    test({{0, 0}, {1, 0}, {2, 0}}, 2);
}