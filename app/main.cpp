#include <iostream>
#include <vector>
#include <random>

using namespace std;

#include "defs.h"

#include "mergesort.h"
#include "quicksort.h"
#include "avltree.h"
#include "hashmap.h"

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

    exemplar::HashMap<int, string> map;
    map.set(0, "adam");
    map.set(1, "jennah");
    map.set(2, "ada");
    map.set(100, "monkey");
    cout << map.get(0) << endl;
    cout << map.get(1) << endl;
    cout << map.get(2) << endl;
    cout << map.get(100) << endl;

    exemplar::HashMap<string, string> map2;
    map2.set("adam", "daddy");
    map2.set("jennah", "mommy");
    map2.set("ada", "baby");
    map2.set("ripley", "doggie");

    cout << map2.get("adam") << endl;
    cout << map2.get("jennah") << endl;
    cout << map2.get("ada") << endl;
    cout << map2.get("ripley") << endl;

    return 0;
}
