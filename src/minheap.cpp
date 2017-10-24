#include "minheap.h"

#include "util.h"

#include <vector>
using namespace std;

namespace exemplar
{
    void minheap_example()
    {
        DBG("\n- Start minheap_example -\n");
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

        exemplar::printVector(v);
        exemplar::printVector(heapSorted);
        DBG("- End minheap_example -\n");
    }
}
