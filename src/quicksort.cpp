#include "quicksort.h"

#include "util.h"

#include <random>

namespace exemplar
{
    void quicksort_example()
    {
        DBG("\n- Start quicksort_example -\n");
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 25);

        vector<char> unsorted;
        for (int i = 0; i < 20; ++i) {
            unsorted.push_back('a' + dis(gen));
        }
        vector<char> sorted = unsorted;
        exemplar::printVector(sorted);
        exemplar::quicksort(sorted);
        exemplar::printVector(sorted);
        DBG("- End quicksort_example -\n");
    }
}
