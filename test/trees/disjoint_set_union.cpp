#include "trees/disjoint_set_union.hpp"

#include <gtest/gtest.h>
#include <math.h>

#define SUITE trees_dsu

TEST(SUITE, InitialState)
{
    DSU dsu(5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(dsu.find(i), i);
        EXPECT_EQ(dsu.meta(i).r, 1);
    }
}

TEST(SUITE, BasicUnion)
{
    DSU dsu(5);
    EXPECT_TRUE(dsu.unite(2, 3));
    EXPECT_EQ(dsu.find(2), dsu.find(3));
    EXPECT_EQ(dsu.meta(2).r, 2);
    EXPECT_EQ(dsu.meta(3).r, 2);
}

TEST(SUITE, MultiUnion)
{
    DSU dsu(5);
    EXPECT_TRUE(dsu.unite(0, 1));
    EXPECT_TRUE(dsu.unite(2, 3));
    EXPECT_TRUE(dsu.unite(0, 3));
    EXPECT_EQ(dsu.find(2), dsu.find(1));
    EXPECT_EQ(dsu.meta(3).r, 4);
}

TEST(SUITE, DuplicatedUnion)
{
    DSU dsu(5);
    EXPECT_TRUE(dsu.unite(0, 1));
    EXPECT_FALSE(dsu.unite(0, 1));
    EXPECT_FALSE(dsu.unite(1, 0));
}

TEST(SUITE, BigNumbers)
{
    const lli N = 1e7;
    DSU dsu(N);
    EXPECT_EQ(dsu.meta(123456).r, 1);
    EXPECT_EQ(dsu.find(9876543), 9876543);
}

TEST(SUITE, BigSets)
{
    const lli N = 1e6;
    DSU dsu(N);

    for (lli i = 0; i + 1 < N; i += 2) {
        EXPECT_TRUE(dsu.unite(i, i + 1));
    }

    for (lli i = 0; i + 1 < N; i += 2) {
        EXPECT_EQ(dsu.find(i), dsu.find(i + 1));
        EXPECT_EQ(dsu.meta(i).r, 2);
    }

    EXPECT_NE(dsu.find(0), dsu.find(2));
}

TEST(SUITE, BigSetsAllJoined)
{
    const lli N = 1e6;
    DSU dsu(N);

    for (lli i = 0; i + 1 < N; i += 1) {
        EXPECT_TRUE(dsu.unite(i, i + 1));
    }

    for (lli i = 0; i + 1 < N; i += 1) {
        EXPECT_EQ(dsu.find(i), dsu.find(i + 1));
    }

    EXPECT_EQ(dsu.meta(1).r, N);
}

struct DSUMin {
    struct Mt {
        lli r;  //@ state
        Mt()
        {  //@ initial state
            r = 1;
        }
    };
    vector<lli> p;  // parents
    vector<Mt> m;   // metadata

    // O(N)
    DSUMin(lli n) : p(n), m(n)
    {
        fora(i, 0, n)
        {
            p[i] = i;
            m[i].r = i;
        }
    }
    // O(1)

    lli find(lli x)
    {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
    bool unite(lli x, lli y)
    {
        lli xrt = find(x), yrt = find(y);
        if (xrt == yrt)
            return false;
        p[yrt] = xrt;
        m[xrt].r = std::min(m[xrt].r, m[yrt].r);  //@ update state
        return true;
    }

    Mt &meta(lli x)
    {
        return m[find(x)];
    }  // O(1)
};

TEST(SUITE, MinimumImplementationBigAmount)
{
    const lli N = 1e6;
    DSUMin dsu(N);

    for (lli i = 0; i + 1 < N; i += 1) {
        EXPECT_TRUE(dsu.unite(i, i + 1));
    }

    for (lli i = 0; i + 1 < N; i += 1) {
        EXPECT_EQ(dsu.find(i), dsu.find(i + 1));
    }

    EXPECT_EQ(dsu.meta(1).r, 0);
}

TEST(SUITE, MinimumImplementation)
{
    DSUMin dsu(9);

    EXPECT_TRUE(dsu.unite(0,1));
    EXPECT_TRUE(dsu.unite(2,3));
    EXPECT_TRUE(dsu.unite(8,7));
    EXPECT_TRUE(dsu.unite(8,3));

    EXPECT_EQ(dsu.meta(8).r, 2);
}