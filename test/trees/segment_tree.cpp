#include "trees/segment_tree.hpp"

#include <gtest/gtest.h>

#include <vector>

#define SUITE trees_segment_tree

TEST(SUITE, BuildAndQuerySingleElements)
{
    std::vector<int> arr = {5, 2, 8, 6, 3};
    STree<int> st(arr);

    EXPECT_EQ(st.query(0).s, 5);
    EXPECT_EQ(st.query(1).s, 2);
    EXPECT_EQ(st.query(2).s, 8);
    EXPECT_EQ(st.query(3).s, 6);
    EXPECT_EQ(st.query(4).s, 3);
}

TEST(SUITE, RangeSumQueries)
{
    std::vector<int> arr = {5, 2, 8, 6, 3};
    STree<int> st(arr);

    EXPECT_EQ(st.query(0, 5).s, 24);
    EXPECT_EQ(st.query(1, 4).s, 16);
    EXPECT_EQ(st.query(2, 3).s, 8);
}

TEST(SUITE, RangeMinQueries)
{
    std::vector<int> arr = {5, 2, 8, 6, 3};
    STree<int> st(arr);

    EXPECT_EQ(st.query(0, 5).mn, 2);
    EXPECT_EQ(st.query(1, 4).mn, 2);
    EXPECT_EQ(st.query(2, 5).mn, 3);
}

TEST(SUITE, PointUpdates)
{
    std::vector<int> arr = {5, 2, 8, 6, 3};
    STree<int> st(arr);

    st.set(2, 1);

    EXPECT_EQ(st.query(2).s, 1);
    EXPECT_EQ(st.query(2).mn, 1);

    EXPECT_EQ(st.query(0, 5).s, 17);
    EXPECT_EQ(st.query(0, 5).mn, 1);
}

TEST(SUITE, MixedOperations)
{
    std::vector<int> arr = {10, 20, 30, 40, 50};
    STree<int> st(arr);

    EXPECT_EQ(st.query(0, 3).s, 60);
    st.set(1, 5);
    EXPECT_EQ(st.query(0, 3).s, 45);
    EXPECT_EQ(st.query(0, 3).mn, 5);

    st.set(0, 1);
    EXPECT_EQ(st.query(0, 3).mn, 1);
}

TEST(SUITE, LargeArraySumAndMin)
{
    const int N = 100000;
    std::vector<long long> arr(N, 1);
    STree<long long> st(arr);
    EXPECT_EQ(st.query(0, N).s, static_cast<long long>(N));
    EXPECT_EQ(st.query(0, N).mn, 1);
}

TEST(SUITE, LargeValues)
{
    std::vector<long long> arr = {(long long)1e12, (long long)1e12,
                                  (long long)1e12};
    STree<long long> st(arr);
    EXPECT_EQ(st.query(0, 3).s, (long long)3e12);
    EXPECT_EQ(st.query(0, 3).mn, (long long)1e12);
}

TEST(SUITE, NegativesAndZeros)
{
    std::vector<int> arr = {0, -5, -2, 0, 7};
    STree<int> st(arr);
    EXPECT_EQ(st.query(0, 5).s, 0);
    EXPECT_EQ(st.query(0, 5).mn, -5);
    st.set(1, 3);
    EXPECT_EQ(st.query(0, 5).mn, -2);
}

TEST(SUITE, SingleElement)
{
    std::vector<int> arr = {42};
    STree<int> st(arr);
    EXPECT_EQ(st.query(0).s, 42);
    EXPECT_EQ(st.query(0, 1).mn, 42);
    st.set(0, -1);
    EXPECT_EQ(st.query(0, 1).s, -1);
    EXPECT_EQ(st.query(0, 1).mn, -1);
}

TEST(SUITE, AllEqual)
{
    std::vector<int> arr(8, 5);
    STree<int> st(arr);
    EXPECT_EQ(st.query(0, 8).s, 40);
    EXPECT_EQ(st.query(0, 8).mn, 5);
}
