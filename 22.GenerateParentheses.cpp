//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(22)
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            queue<Node> q;
            q.push(Node());
            while(!q.empty()) {
                auto p = q.front();
                q.pop();
                if (p.used == n) {
                    if (p.opening == 0) result.push_back(p.value);
                    else result.push_back(p.value + string(p.opening, ')'));
                } else {
                    q.push(p.appending(true));
                    if (p.opening > 0) q.push(p.appending(false));
                }
            }

            return result;
        }
    private:

        struct Node {
            string value;
            int opening;
            int used;
            Node() : value("("), opening(1), used(1) {}
            Node appending(bool open) {
                if (open) {
                    return Node(value + "(", opening + 1, used + 1);
                } else {
                    return Node(value + ")", opening - 1, used);
                }
            }
        private:
            Node(string val, int o, int u) : value(val), opening(o), used(u) {}
        };
SOLUTION_END

TEST_BEGIN(22)
    void test(int n, const vector<string>& expected) {
        EXPECT_THAT(Solution().generateParenthesis(n), ::testing::UnorderedElementsAreArray(expected));
    }
TEST_END

MYTEST_F(22, Example) {
    test(3, {
        "((()))",
        "(()())",
        "()()()",
        "()(())",
        "(())()"
    });
}
