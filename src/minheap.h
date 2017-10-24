#pragma once

// MinHeap
// The smallest element will always be the root.
// Allows for O(1) retrieval of smallest element.
// 
// The data structure is stored as a simple array, with formulae
// to retrieve indices for parent, left child & right child nodes.
// 
// New items are simply added to the end and bubbled up the tree
// until a smaller parent is reached. This is done by iteratively
// swapping with parents.
//
// When the smallest item is removed, the "heapfiy" operation restores
// the min heap. This is done by moving the last item to the root and
// recursively swapping the item with the smaller of its children until
// both children are larger.

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

    void minheap_example();
}
