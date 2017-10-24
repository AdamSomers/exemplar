#include "bst.h"

#include "util.h"

namespace exemplar
{
    void bst_example()
    {
        DBG("\n- Start bst_example -\n");
        exemplar::BSTNode<int>* root = new exemplar::BSTNode<int>(10);
        root->insert(8);
        root->insert(12);
        vector<int> expected = { 8, 10, 12 };
        vector<int> contents;
        root->contentsInOrder(contents);
        printVector(contents);
        DBG("- End bst_example -\n");
    }
}
