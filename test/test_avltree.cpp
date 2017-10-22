#include <gtest/gtest.h>
#include "avltree.h"

TEST(AVLTree, avlTreeTest1)
{
    vector<int> expectedResult = { 30, 20, 10, 25, 40, 50 };
    exemplar::AVLTreeNode<int>* tree = new exemplar::AVLTreeNode<int>(10);
    tree = tree->insert(20);
    tree = tree->insert(30);
    tree = tree->insert(40);
    tree = tree->insert(50);
    tree = tree->insert(25);
    vector<int> v;    
    tree->contentsPreOrder(v);
    ASSERT_TRUE(expectedResult == v);
}

