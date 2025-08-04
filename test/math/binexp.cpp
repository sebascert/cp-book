#include "math/binexp.hpp"

#include <gtest/gtest.h>

#define SUITE math_binexp

TEST(SUITE, NoModulus)
{
    EXPECT_EQ(binexp(0LL, 0), 1);
    EXPECT_EQ(binexp(1LL, 0), 1);
    EXPECT_EQ(binexp(123456LL, 0), 1);

    EXPECT_EQ(binexp(0LL, 1), 0);
    EXPECT_EQ(binexp(0LL, 10), 0);

    EXPECT_EQ(binexp(1LL, 1000000000ULL), 1);

    EXPECT_EQ(binexp(2LL, 63), 9223372036854775808ULL);

    EXPECT_EQ(binexp(3LL, 20), 3486784401LL);

    ull big_exp = 1000000ULL;
    (void)binexp(2ULL, big_exp);

    EXPECT_EQ(binexp(0LL, big_exp), 0);
}

TEST(SUITE, WithModulus)
{
    EXPECT_EQ(binexp(0LL, 0, 1000LL), 1);
    EXPECT_EQ(binexp(123LL, 0, 1LL), 1);
    EXPECT_EQ(binexp(123LL, 0, 987654321LL), 1);

    EXPECT_EQ(binexp(123LL, 10, 1LL), 0);
    EXPECT_EQ(binexp(0LL, 100, 1LL), 0);
    EXPECT_EQ(binexp(123LL, 0, 1LL), 1);

    EXPECT_EQ(binexp(0LL, 10, 1000LL), 0);

    EXPECT_EQ(binexp(1000LL, 10, 1000LL), 0);

    ull mod = 1000000007ULL;
    EXPECT_EQ(binexp(2ULL, 1000000000ULL, mod), 140625001);
    EXPECT_EQ(binexp(123456789ULL, 123456ULL, mod), 116286100);

    ull big_exp = 1000000000000ULL;

    ull result = binexp(2ULL, big_exp, mod);
    EXPECT_GE(result, 0ULL);
    EXPECT_LT(result, mod);
}
