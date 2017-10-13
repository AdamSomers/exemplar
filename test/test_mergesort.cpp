#include <gtest/gtest.h>
#include "mergesort.h"

TEST(MergeSort, sortingTest1)
{
    vector<int> v = { 1, 4, 3, 6, 8, 111, 5, 2, 4};
    vector<int> vs = { 1, 2, 3, 4, 4, 5, 6, 8, 111 };
    exemplar::mergesort(v);
    ASSERT_TRUE(v == vs);
}

TEST(MergeSort, sortingTest2)
{
    vector<int> v = { 5, 4, 3, 2, 1};
    vector<int> vs = { 1, 2, 3, 4, 5 };
    exemplar::mergesort(v);
    ASSERT_TRUE(v == vs);
}

