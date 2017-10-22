#pragma once

#include "util.h"

using namespace std;

// MinHeap

namespace exemplar
{
    template <class T> class MinHeap
    {
    public:
        MinHeap(int initialCapacity) : capacity(initialCapacity)
        {
            data = new T[capacity];
        }

        ~MinHeap()
        {
            delete [] data;
        }

        void minHeapify(int i)
        {
            int l = left(i);
            int r = right(i);
            int smallest = i;
            if (l < size && data[l] < data[i]) {
                smallest = l;
            }
            if (r < size && data[r] < data[smallest]) {
                smallest = r;
            }
            if (smallest != i) {
                swap(i, smallest);
                minHeapify(smallest);
            }
        }

        T getMin()
        {
            return data[0];
        }

        T extractMin()
        {
            T rootVal = data[0];

            if (size == 1) {
                size --;
                return rootVal;
            }

            data[0] = data[size - 1];
            size--;
            minHeapify(0);
            return rootVal;
        }

        void insert(const T& newVal)
        {
            int i = size;
            data[i] = newVal;
            size++;
            while (i != 0 && data[parent(i)] > data[i]) {
                swap(parent(i), i);
                i = parent(i);
            }
        }

    private:
        void swap(int i, int j)
        {
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }

        int parent(int i)
        {
            return (i - 1) / 2;
        }

        int left(int i)
        {
            return 2 * i + 1;
        }

        int right(int i)
        {
            return 2 * i + 2;
        }

        T* data = nullptr;
        int capacity = 0;
        int size = 0;
    };
}