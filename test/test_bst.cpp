#include <gtest/gtest.h>
#include "bst.h"

#include <vector>
#include <iostream>
using namespace std;

TEST(BST, inOrder)
{
    exemplar::BSTNode<int>* root = new exemplar::BSTNode<int>(10);
    root->insert(8);
    root->insert(12);
    vector<int> expected = { 8, 10, 12 };
    vector<int> contents;
    root->contentsInOrder(contents);
    ASSERT_TRUE(contents == expected);
}

TEST(BST, preOrder)
{
    exemplar::BSTNode<int>* root = new exemplar::BSTNode<int>(10);
    root->insert(8);
    root->insert(12);
    vector<int> expected = { 10, 8, 12 };
    vector<int> contents;
    root->contentsPreOrder(contents);
    ASSERT_TRUE(contents == expected);
}

TEST(BST, postOrder)
{
    exemplar::BSTNode<int>* root = new exemplar::BSTNode<int>(10);
    root->insert(8);
    root->insert(12);
    vector<int> expected = { 8, 12, 10 };
    vector<int> contents;
    root->contentsPostOrder(contents);
    ASSERT_TRUE(contents == expected);
}

TEST(BST, orderedList)
{
    exemplar::BSTNode<int>* root = new exemplar::BSTNode<int>(10);
    root->insert(100);
    root->insert(90);
    root->insert(80);
    root->insert(20);
    root->insert(30);
    root->insert(40);
    root->insert(70);
    vector<int> expected = { 10, 20, 30, 40, 70, 80, 90, 100 };
    vector<int> contents;
    root->contentsInOrder(contents);
    ASSERT_TRUE(contents == expected);
}

TEST(BST, shallowDepth)
{
    exemplar::BSTNode<int>* root = new exemplar::BSTNode<int>(50);
    root->insert(30);
    root->insert(40);
    root->insert(20);
    root->insert(70);
    root->insert(60);
    root->insert(80);
    vector<int> contents;
    ASSERT_TRUE(root->getDepth() == 3);
}

TEST(BST, deepDepth)
{
    exemplar::BSTNode<int>* root = new exemplar::BSTNode<int>(10);
    root->insert(20);
    root->insert(30);
    root->insert(40);
    root->insert(50);
    root->insert(60);
    root->insert(70);
    root->insert(80);
    vector<int> contents;
    ASSERT_TRUE(root->getDepth() == 8);
}