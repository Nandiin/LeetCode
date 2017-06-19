//
// Created by Nandiin Borjigin on 17/04/2017.
//

#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(67)
        string addBinary(string a, string b) {
            if ("0" == a && "0" == b) return "0";
            string ret = "";
            bool carry = false;
            while(!a.empty() && !b.empty()) {
                const int aBit = a.back() - '0';
                const int bBit = b.back() - '0';
                const int sum = aBit + bBit + (carry ? 1 : 0);
                const char c = '0' + (char) (sum % 2);
                ret = string(1, c) + ret;
                carry = sum / 2 > 0;
                a.pop_back();
                b.pop_back();
            }

            string* remainder = nullptr;

            if (!a.empty()) {
                remainder = &a;
            } else if (!b.empty()) {
                remainder = &b;
            }
            if (nullptr != remainder) ret = (carry ? addBinary(*remainder, "1") : *remainder) + ret;
            else if (carry) ret = "1" + ret;

            return ret;
        }
SOLUTION_END

TEST_BEGIN(67)
    void test(string input[], string expected) {
        string output = Solution().addBinary(input[0], input[1]);
        EXPECT_EQ(output, expected);
    }
TEST_END

MYTEST_F(67, Case1) {
    string input[] = { "11", "1" };
    test(input, "100");
}

MYTEST_F(67, Case2) {
    string input[] = {
            "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101",
            "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011"
    };
    test(input, "110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000");
}