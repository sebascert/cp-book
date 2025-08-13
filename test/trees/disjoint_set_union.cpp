#include "../../src/trees/disjoint_set_union.hpp"

#include <gtest/gtest.h>

#define SUITE trees_dsu

TEST(SUITE, InitialState) {
    DSU dsu(5);
    fora(i, 0, 5) {
        EXPECT_EQ(dsu.find(i), i);
        EXPECT_EQ(dsu.meta(i).r, 1);
    }
}

TEST(SUITE, BasicUnion) {
    DSU dsu(5);
    EXPECT_TRUE(dsu.unite(2, 3));
    EXPECT_EQ(dsu.find(2), dsu.find(3));
    EXPECT_EQ(dsu.meta(2).r, 2);
    EXPECT_EQ(dsu.meta(3).r, 2);
}

TEST(SUITE, MultiUnion) {
    DSU dsu(5);
    EXPECT_TRUE(dsu.unite(0, 1));
    EXPECT_TRUE(dsu.unite(2, 3));
    EXPECT_TRUE(dsu.unite(0, 3));
    EXPECT_EQ(dsu.find(2), dsu.find(1));
    EXPECT_EQ(dsu.meta(3).r, 4);
}

TEST(SUITE, DuplicatedUnion) {
    DSU dsu(5);
    EXPECT_TRUE(dsu.unite(0, 1));
    EXPECT_FALSE(dsu.unite(0, 1));
    EXPECT_FALSE(dsu.unite(1, 0));
}