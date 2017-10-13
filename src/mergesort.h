#pragma once

#include <vector>

#include "defs.h"
#include "util.h"

using namespace std;

// Mergesort
// Split array in half, recurse to each half, combine elements of 
// halves in sorted order, overwritng the original.
// O(n*log(n)) time. O(n) space.

namespace exemplar
{
    template <class T> void mergesort(vector<T>& v)
    {
        DBG("\n- Start Mergesort -\n");
        exemplar::printVector(v);
        mergesort(v, 0, (int)v.size() - 1);
        exemplar::printVector(v);
        DBG("- End Mergesort -\n");
    }

    template <class T> void mergesort(vector<T>& v, int start, int end)
    {
        if (start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;
        mergesort(v, start, mid);
        mergesort(v, mid + 1, end);
        combineHalves(v, start, end);
    }

    template <class T> void combineHalves(vector<T>& v, int start, int end)
    {
        vector<T> combined;
        int mid = start + (end - start) / 2;
        int i1 = start;
        int i2 = mid + 1;
        while (i1 <= mid && i2 <= end) {
            if (v[i1] <= v[i2]) {
                combined.push_back(v[i1]);
                i1++;
            }
            else {
                combined.push_back(v[i2]);
                i2++;
            }
        }
        while (i1 <= mid) {
            combined.push_back(v[i1]);
            i1++;
        }
        while (i2 <= end) {
            combined.push_back(v[i2]);
            i2++;
        }
        for (int i = 0; i < combined.size(); ++i) {
            v[start + i] = combined[i];
        }
    }
}
