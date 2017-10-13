#pragma once

#include <vector>

#include "util.h"

using namespace std;

// Quicksort
// Choose a pivot point (midpoint will do).
// Parition the array, putting elements on the correct side of the pivot.
// Keep track of where the partition ended.
// Recurse on each part of the partitioned array.
//
// Implementation of partition:
// Walk pointers from ends inward while values are already on the correct side.
// After this adjustment, swap the values and move the pointers inward.
// Repeat until pointers cross.
// Return the index of the left pointer.
//
// Complixity: O(n*log(n)) average case. O(n^2) worst case.

namespace exemplar
{
    template <class T> void quicksort(vector<T>& v)
    {
        DBG("\n- Start Quicksort -\n");
        exemplar::printVector(v);
        quicksort(v, 0, (int)v.size() - 1, (int)v.size() / 2);
        exemplar::printVector(v);
        DBG("- End Quicksort -\n");
    }

    template <class T> void quicksort(vector<T>& v, int start, int end, int pivot)
    {
        if (start >= end) {
            return;
        }

        int partitionIndex = partition(v, start, end, pivot);
        quicksort(v, start, partitionIndex - 1, (start + partitionIndex - 1) / 2);
        quicksort(v, partitionIndex, end, (partitionIndex + end) / 2);
    }

    template <class T> int partition(vector<T>& v, int start, int end, int pivot)
    {
        int left = start;
        int right = end;
        T pv = v[pivot];
        while (left <= right) {
            while (v[left] < pv) {
                left++;
            }
            while (v[right] > pv) {
                right--;
            }
            if (left <= right) {
                swap(v, left, right);
                left++;
                right--;
            }
        }
        return left;
    }

    template <class T> void swap(vector<T>& v, int a, int b)
    {
        T temp = v[a];
        v[a] = v[b];
        v[b] = temp;
    }
}