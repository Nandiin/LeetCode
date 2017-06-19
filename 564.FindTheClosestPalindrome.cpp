//
// Created by nandiin on 19/06/2017.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(564)
        string nearestPalindromic(string n) {
            if (n == "0") return "1";
            else if (n.length() == 1) return string(1, n[0] - 1);
            auto len = n.length();
            auto mid = len / 2;
            auto nCopy = n;
            for (auto i = 0; i < mid; ++i) {
                n[len - 1 - i] = n[i];
            }
            auto decreased = decrease(n, 0);
            auto increased = increase(n, 0);
            vector<string> candidates = { decreased, n, increased };
            vector<long> distances = { distance(decreased, nCopy), distance(n, nCopy), distance(increased, nCopy) };
            int minIndex = -1;
            for (auto i = 0; i < 3; ++i) {
                if (distances[i] == 0) continue;
                else if (minIndex == -1 || distances[i] < distances[minIndex]) minIndex = i;
            }
            return candidates[minIndex];
        }
    private:

        string decrease(const string& n, int pos) {
            auto offset = n.length() % 2 == 0 ? 1 : 0;
            auto mid = n.length() / 2 - offset;
            auto threshold = mid > pos ? '0' : '1';
            auto ret = n;
            if (n[mid - pos] > threshold ) {
                ret[mid - pos] = n[mid - pos] - (char)1;
                ret[mid + pos + offset] = ret[mid - pos];
            } else {
                // the position can not be decreased
                if (mid == pos) {
                    // it is the first digit
                    return string(n.length() - 1, '9');
                } else {
                    ret[mid - pos] = '9';
                    ret[mid + pos + offset] = '9';
                    return decrease(ret, pos + 1);
                }
            }
            return ret;
        }

        string increase(const string& n, int pos) {
            auto ret = n;
            auto offset = n.length() % 2 == 0 ? 1 : 0;
            auto mid = n.length() / 2 - offset;
            if (n[mid - pos] < '9') {
                ret[mid - pos] = n[mid - pos] + (char)1;
                ret[mid + pos + offset] = ret[mid - pos];
            } else {
                // the position can not be increased
                if (mid == pos) {
                    // it is the first digit
                    return "1" + string(n.length() - 1, '0') + "1";
                } else {
                    ret[mid - pos] = '0';
                    ret[mid + pos + offset] = '0';
                    return increase(ret, pos + 1);
                }
            }
            return ret;
        }


        long distance(const string &a, const string &b) {
            return labs(stol(a) - stol(b));
        }

SOLUTION_END

TEST_BEGIN(564)
    void test(const string& input, const string& expected) {
        auto i = input;
        EXPECT_EQ(Solution().nearestPalindromic(i), expected);
    }
TEST_END

MYTEST_F(564, Example) {
    test("123", "121");
}

MYTEST_F(564, OneDigit) {
    test("1", "0");
}

MYTEST_F(564, Zero) {
    test("0", "1");
}

MYTEST_F(564, Nine) {
    test("9", "8");
}

MYTEST_F(564, TensPower) {
    test("10", "9");
    test("100", "99");
    test("100000", "99999");
}
MYTEST_F(564, Eleven) {
    test("11", "9");
}

MYTEST_F(564, Twelve) {
    test("12", "11");
}

MYTEST_F(564, NintyNine) {
    test("99", "101");
}
