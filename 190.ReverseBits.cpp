
#include <gtest/gtest.h>
#include "header.h"

SOLUTION_BEGIN(190)
        uint32_t reverseBits(uint32_t n) {
            uint32_t res = 0u;
            for (auto i = 0; i < 32; ++i) {
                if (n == 0) return res << (32 - i);
                res <<= 1;
                res |= (n & 1u);
                n >>= 1;
            }
            return res;
        }
SOLUTION_END

TEST_BEGIN(190)
    void test(uint32_t input, uint32_t expected) {
        EXPECT_EQ(Solution().reverseBits(input), expected);
    }
TEST_END

MYTEST_F(190, Simple) {
    test(2, 0x40000000);
}

MYTEST_F(190, Example) {
    test(43261596, 964176192);
}

