#include <gtest/gtest.h>
#include "minheap.h"

#include <algorithm>

TEST(MinHeap, getMinTest1)
{
    vector<int> v = { 8, 4, 3, 6, 1, 111, 5, 2, 4 };
    exemplar::MinHeap<int> heap(100);
    for (auto i : v) {
        heap.insert(i);
    }
    int val = heap.getMin();
    ASSERT_TRUE(val == 1);
}

TEST(MinHeap, getMinTest2)
{
    vector<int> v = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    exemplar::MinHeap<int> heap(100);
    for (auto i : v) {
        heap.insert(i);
    }
    int val = heap.getMin();
    ASSERT_TRUE(val == 1);
}

TEST(MinHeap, getMinTest3)
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    exemplar::MinHeap<int> heap(100);
    for (auto i : v) {
        heap.insert(i);
    }
    int val = heap.getMin();
    ASSERT_TRUE(val == 1);
}

TEST(MinHeap, extractMinTest1)
{
    vector<int> v = { 8, 4, 3, 6, 1, 111, 5, 2, 4 };
    exemplar::MinHeap<int> heap(100);
    for (auto i : v) {
        heap.insert(i);
    }
    int val = heap.extractMin();
    ASSERT_TRUE(val == 1);
}

TEST(MinHeap, extractMinTest2)
{
    vector<int> v = { 8, 4, 3, 6, 1, 111, 5, 2, 4 };
    exemplar::MinHeap<int> heap(100);
    for (auto i : v) {
        heap.insert(i);
    }
    heap.extractMin();
    int val = heap.extractMin();
    ASSERT_TRUE(val == 2);
}

TEST(MinHeap, extractMinTest3)
{
    vector<int> v = { 8, 4, 3, 6, 1, 111, 5, 2, 4 };
    exemplar::MinHeap<int> heap(100);
    for (auto i : v) {
        heap.insert(i);
    }
    heap.extractMin();
    heap.extractMin();
    int val = heap.extractMin();
    ASSERT_TRUE(val == 3);
}

TEST(MinHeap, HeapSort)
{
    vector<int> v = { 10, 12, 8, 4, 17, 111, 2000000, -11, -4, 0 };
    vector<int> sorted = v;
    sort(sorted.begin(), sorted.end());
    vector<int> heapSorted;
    exemplar::MinHeap<int> heap(100);
    for (auto i : v) {
        heap.insert(i);
    }
    for (int i = 0; i < v.size(); ++i) {
        heapSorted.push_back(heap.extractMin());
    }
    ASSERT_TRUE(heapSorted == sorted);
}
