#include "avltree.h"

#include "util.h"

namespace exemplar
{
    void avltree_example()
    {
        DBG("\n- Start avltree_example -\n");
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
        DBG("- End avltree_example -\n");
    }
}
