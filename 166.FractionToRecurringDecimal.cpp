
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "header.h"

SOLUTION_BEGIN(166)
        string fractionToDecimal(int numerator, int denominator) {
            long num = abs((long)numerator);
            long den = abs((long)denominator);
            string integral = std::to_string(num / den);
            if ((long)numerator * (long)denominator < 0) integral.insert(0, "-");
            num %= den;
            if (num != 0) integral += ".";
            vector<long> dividends;
            string decimal;
            while (0 != num) {
                auto dividend = num * 10;
                size_t i = 0;
                while (i < dividends.size() && dividends[i] != dividend) ++i;
                if (i < dividends.size()) {
                    decimal.insert(i, "(");
                    decimal += ")";
                    break;
                }
                dividends.push_back(dividend);
                decimal += std::to_string(dividend / den);
                num = dividend % denominator;
            }
            return integral + decimal;
        }
SOLUTION_END

TEST_BEGIN(166)
    void test(int numerator, int denominator, const string& expected) {
        EXPECT_EQ(Solution().fractionToDecimal(numerator, denominator), expected);
    }
TEST_END


MYTEST_F(166, Example1) {
    test(1, 2, "0.5");
}

MYTEST_F(166, Example2) {
    test(2, 1, "2");
}

MYTEST_F(166, Example3) {
    test(2, 3, "0.(6)");
}

MYTEST_F(166, Overflow) {
    test(-2147483648, -1, "2147483648");
}

MYTEST_F(166, Negative) {
    test(-50, 8, "-6.25");
}

