//
// Created by Nandiin Borjigin on 10/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(332)
        vector<string> findItinerary(vector<pair<string, string>> tickets) {
            return find("JFK", tickets);
        }

    private:
        vector<string> find(string departure, vector<pair<string, string>> tickets) {

            if (tickets.empty()) return vector<string>();
            if (tickets.size() == 1 && tickets[0].first == departure)
                return vector<string>({tickets[0].first, tickets[0].second});

            vector<pair<int, string>> candidates;

            auto ret = vector<string>({departure});

            for (auto i = 0; i < tickets.size(); ++i) {
                if (tickets[i].first == departure) {
                    candidates.push_back(make_pair(i, tickets[i].second));
                }
            }

            const auto sortFunc = [](pair<int, string> lhs, pair<int, string> rhs) -> bool {
                return lhs.second < rhs.second;
            };
            std::sort(candidates.begin(), candidates.end(), sortFunc);

            for (auto i = 0; i < candidates.size(); ++i) {
                auto candidate = candidates[i];
                tickets.erase(tickets.begin() + candidate.first);
                auto sub = find(candidate.second, tickets);
                if (sub.size() == tickets.size() + 1) {
                    ret.insert(ret.end(), sub.begin(), sub.end());
                    break;
                } else {
                    tickets.insert(tickets.begin() + candidate.first, make_pair(departure, candidate.second));
                }
            }

            return ret;
        }
SOLUTION_END

TEST_BEGIN(332)
    void test(string input[][2], int n, string expected[]) {
        vector<pair<string, string>> inputVec;
        for (auto i = 0; i < n; ++i) {
            inputVec.push_back(make_pair(input[i][0], input[i][1]));
        }
        vector<string> expectedVec;
        for (auto i = 0; i < n + 1; ++i) {
            expectedVec.push_back(expected[i]);
        }
        EXPECT_EQ(Solution().findItinerary(inputVec), expectedVec);
    }
TEST_END

MYTEST_F(332, Case1) {
    string input[][2] = { { "MUC", "LHR" }, { "JFK", "MUC" }, { "SFO", "SJC" }, { "LHR", "SFO" } };
    string expected[] = { "JFK", "MUC", "LHR", "SFO", "SJC" };
    test(input, 4, expected);
}

MYTEST_F(332, Case2) {
    string input[][2] = { { "JFK","SFO" },{ "JFK","ATL" },{ "SFO","ATL" },{ "ATL","JFK" },{ "ATL","SFO" } };
    string expected[] = { "JFK","ATL","JFK","SFO","ATL","SFO" };
    test(input, 5, expected);
}