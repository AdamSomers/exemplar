#include "mergesort.h"
#include "quicksort.h"
#include "avltree.h"
#include "hashmap.h"
#include "bst.h"
#include "minheap.h"

#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
    exemplar::mergesort_example();
    exemplar::quicksort_example();
    exemplar::bst_example();
    exemplar::avltree_example();
    exemplar::hashmap_example();
    exemplar::minheap_example();

    return 0;
}
