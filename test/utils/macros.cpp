#include "utils/macros.hpp"

#include <gtest/gtest.h>

#define SUITE utils_macros

alias_t(long long, lli);

TEST(SUITE, Sz)
{
    size_t size = 10;
    std::vector<int> v(size);
    EXPECT_EQ(sz(v), size);
}
TEST(SUITE, Fora)
{
    vector<lli> res;

    res.clear();
    fora(i, 0, 5) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{0, 1, 2, 3, 4}));

    res.clear();
    fora(i, -3, 2) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{-3, -2, -1, 0, 1}));

    res.clear();
    fora(i, 2, 2) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{}));

    res.clear();
    fora(i, 5, 2) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{}));

    res.clear();
    fora(i, -2, -2) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{}));
}

TEST(SUITE, Ford)
{
    vector<lli> res;

    res.clear();
    ford(i, 4, -1) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{3, 2, 1, 0, -1}));

    res.clear();
    ford(i, 1, -3) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{0, -1, -2, -3}));

    res.clear();
    ford(i, 2, 2) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{}));

    res.clear();
    ford(i, -2, 5) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{}));

    res.clear();
    ford(i, -1, -1) res.push_back(i);
    EXPECT_EQ(res, (vector<lli>{}));
}

TEST(SUITE, Mid)
{
    EXPECT_EQ(mid(1, 1), 1);
    EXPECT_EQ(mid(1, 3), 2);
    EXPECT_EQ(mid(0, 10), 5);
    EXPECT_EQ(mid(-10, 10), mid(0, 20) - 10);
    EXPECT_EQ(mid(-10, 5), mid(0, 15) - 10);
    EXPECT_EQ(mid(POSINF, POSINF), POSINF);
    EXPECT_EQ(mid(NEGINF, NEGINF), NEGINF);
    EXPECT_EQ(mid(POSINF - 1, POSINF), POSINF - 1);
    EXPECT_EQ(mid(NEGINF + 1, 0), NEGINF / 2);
}

TEST(SUITE, BinTreeChilds)
{
    EXPECT_EQ(btl(1), 2);
    EXPECT_EQ(btl(2), 4);
    EXPECT_EQ(btl(3), 6);
    EXPECT_EQ(btl(4), 8);
    EXPECT_EQ(btr(1), btl(1) + 1);
    EXPECT_EQ(btr(2), btl(2) + 1);
    EXPECT_EQ(btr(3), btl(3) + 1);
    EXPECT_EQ(btr(4), btl(4) + 1);
}

TEST(SUITE, Inf)
{
    EXPECT_EQ(INF(int, max), std::numeric_limits<int>::max());
    EXPECT_EQ(INF(double, min), std::numeric_limits<double>::min());
}

// Test alias_t macro
TEST(SUITE, AliasT)
{
    alias_t(int, myint);

    int i = 10;
    myint mi = 10;
    EXPECT_EQ(i, mi);

    vec v = {1, 2, 3};
    pr p = {4, 5};

    EXPECT_EQ(POSINF, numeric_limits<int>::max());
    EXPECT_EQ(NEGINF, numeric_limits<int>::min());
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(p.first, 4);
    EXPECT_EQ(p.second, 5);
}

// Test iter macro
TEST(SUITE, Iter)
{
    std::vector<int> v = {42, 7, 13, 99, 1, 73, 5, 88, 21, 3};
    std::sort(all(v));

    std::vector<int> expected = {1, 3, 5, 7, 13, 21, 42, 73, 88, 99};
    EXPECT_EQ(v, expected);
}
