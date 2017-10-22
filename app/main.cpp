#include <iostream>
#include <vector>
#include <random>

using namespace std;

#include "defs.h"

#include "mergesort.h"
#include "quicksort.h"
#include "avltree.h"
#include "util.h"

int main(int argc, const char* argv[])
{
    DBG("Hello!\n");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 25);

    vector<char> unsorted;
    for (int i = 0; i < 20; ++i) {
        unsorted.push_back('a' + dis(gen));
    }
    vector<char> sorted = unsorted;
    exemplar::mergesort(sorted);
    sorted = unsorted;
    exemplar::quicksort(sorted);

    exemplar::AVLTreeNode<int>* tree = new exemplar::AVLTreeNode<int>(10);
    vector<int> v;
    tree->contentsPreOrder(v);
    exemplar::printVector(v);
    tree = tree->insert(20);
    v.clear();
    tree->contentsPreOrder(v);
    exemplar::printVector(v);
    tree = tree->insert(30);
    v.clear();
    tree->contentsPreOrder(v);
    exemplar::printVector(v);
    tree = tree->insert(40);
    v.clear();
    tree->contentsPreOrder(v);
    exemplar::printVector(v);
    tree = tree->insert(50);
    v.clear();
    tree->contentsPreOrder(v);
    exemplar::printVector(v);
    tree = tree->insert(25);
    v.clear();
    tree->contentsPreOrder(v);
    exemplar::printVector(v);
    return 0;
}
