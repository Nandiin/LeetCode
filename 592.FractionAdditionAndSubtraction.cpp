#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(592)
        string fractionAddition(string expression) {
            if (expression[0] != '-') expression = "+" + expression;
            auto start = 0u;
            auto pos = 1u;
            Fraction result;
            while (pos <= expression.length()) {
                ++pos;
                if (expression[pos] != '-' && expression[pos] != '+') continue;
                result += Fraction(expression.substr(start, pos - start));
                start = pos;
                pos++;
            }
            result += Fraction(expression.substr(start));

            return result.toString();
        }
    private:
        struct Fraction {

            Fraction() {
                numerator = 0;
                denominator = 1;
            }

            explicit Fraction(const string& str) {
                auto pos = 1u;
                while (str[pos] != '/') ++pos;
                numerator = std::stoi(str.substr(1, pos - 1));
                denominator = std::stoi(str.substr(pos + 1));
                if (str[0] == '-') numerator *= -1;
            }

            const string toString() const {
                auto divisor = abs(gcd(numerator, denominator));
                return std::to_string(numerator / divisor) + "/" + std::to_string(denominator / divisor);
            }

            inline Fraction operator+ (const Fraction other) const {
                auto d = lcm(denominator, other.denominator);
                auto scale1 = d / denominator;
                auto scale2 = d / other.denominator;
                auto n = numerator * scale1 + other.numerator * scale2;
                return {n, d};
            }

            void operator+= (const Fraction rhs) {
                *this = *this + rhs;
            }

        private:
            int numerator;
            int denominator;
            Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator) {}
            static int gcd(int a, int b) {
                auto temp = a;
                if (a < b) {
                    a = b;
                    b = temp;
                }

                while (b != 0) {
                    temp = a % b;
                    a = b;
                    b = temp;
                }
                return a;
            }
            static int lcm(int a, int b) {
                return a * b / gcd(a, b);
            }
        };
SOLUTION_END


TEST_BEGIN(592)
    void test(const string& input, const string& expected) {
        EXPECT_EQ(Solution().fractionAddition(input), expected);
    }
TEST_END


MYTEST_F(592, Example1) {
    test("-1/2+1/2", "0/1");
}

MYTEST_F(592, Case1) {
    test("1/3-1/2", "-1/6");
}

