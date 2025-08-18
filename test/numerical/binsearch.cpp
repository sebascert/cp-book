#include "numerical/binsearch.hpp"

#include <gtest/gtest.h>

#include <cfloat>
#include <cmath>

#define SUITE numerical_binsearch

static bool ge_target_7_int(int x)
{
    return x >= 7;
}
static bool ge_target_k_int_0(int x)
{
    return x >= 0;
}
static bool ge_target_k_int_10(int x)
{
    return x >= 10;
}

static bool square_ge_30_f(f x)
{
    return x * x >= 30.0f;
}
static bool square_ge_2_lf(lf x)
{
    return x * x >= 2.0;
}

TEST(SUITE, FirstTrue_Middle_IntRange)
{
    int res = binsearch<int>(0, 10, ge_target_7_int);

    EXPECT_TRUE(ge_target_7_int(res));
    if (res > 0)
        EXPECT_FALSE(ge_target_7_int(res - 1));
}

TEST(SUITE, FirstTrue_AtLowerBound_IntRange)
{
    int res = binsearch<int>(0, 10, ge_target_k_int_0);

    EXPECT_TRUE(ge_target_k_int_0(res));
    EXPECT_EQ(res, 0);
}

TEST(SUITE, FirstTrue_AtUpperBound_IntRange)
{
    int res = binsearch<int>(0, 10, ge_target_k_int_10);

    EXPECT_TRUE(ge_target_k_int_10(res));
    if (res > 0)
        EXPECT_FALSE(ge_target_k_int_10(res - 1));
    EXPECT_EQ(res, 10);
}

TEST(SUITE, LargeRange_Int)
{
    const int T = 123456789;
    auto p = [](int x) -> bool { return x >= 123456789; };

    int res = binsearch<int>(0, 1000000000, p);
    EXPECT_TRUE(p(res));
    if (res > 0)
        EXPECT_FALSE(p(res - 1));
    EXPECT_EQ(res, T);
}

TEST(SUITE, Float_FirstTrue_UsingSquareThreshold)
{
    f res = binsearch<f, ui32>(1.0f, 100.0f, square_ge_30_f);

    EXPECT_TRUE(square_ge_30_f(res));

    f prev = std::nextafter(res, 0.0f);
    EXPECT_FALSE(square_ge_30_f(prev));

    EXPECT_NEAR(static_cast<double>(res), std::sqrt(30.0), 1e-3);
}

TEST(SUITE, Double_FirstTrue_UsingSquareThreshold)
{
    lf res = binsearch<lf, ui64>(1.0, 10.0, square_ge_2_lf);

    EXPECT_TRUE(square_ge_2_lf(res));

    lf prev = std::nextafter(res, 0.0);
    EXPECT_FALSE(square_ge_2_lf(prev));

    EXPECT_NEAR(res, std::sqrt(2.0), 1e-12);
}

TEST(SUITE, Float_FirstTrue_AtLowerBound)
{
    auto p = [](f x) -> bool { return x >= 1.0f; };
    f res = binsearch<f, ui32>(1.0f, 10.0f, p);

    EXPECT_TRUE(p(res));
    f prev = std::nextafter(res, 0.0f);
    EXPECT_FALSE(p(prev));
    EXPECT_EQ(res, 1.0f);
}

TEST(SUITE, Double_FirstTrue_CloseToUpperBound)
{
    auto p = [](lf x) -> bool { return x >= 9.999999999; };
    lf res = binsearch<lf, ui64>(1.0, 10.0, p);

    EXPECT_TRUE(p(res));
    lf prev = std::nextafter(res, 0.0);
    EXPECT_FALSE(p(prev));
}
