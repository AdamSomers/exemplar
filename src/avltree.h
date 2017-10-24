#pragma once

#include <vector>

using namespace std;

// AVL Tree
// A balanced binary search tree with the constraint that
// no two subtrees may differ in height by more than 1 for any given node.
// After insertion, the new height is checked and one of four rotations
// cases must occur:

// Left Left imbalance
//       z                                      y 
//      / \                                   /   \
//     y   T4      Right Rotate (z)          x      z
//    / \          - - - - - - - - ->      /  \    /  \
//   x   T3                               T1  T2  T3  T4
//  / \
// T1   T2

// Left Right imbalance
//       z                                z                           x
//      / \                             /   \                        /  \
//     y   T4  Left Rotate (y)         x     T4  Right Rotate(z)    y     z
//    / \      - - - - - - - - ->     /  \       - - - - - - - ->  / \   / \
//   T1   x                          y    T3                     T1  T2 T3  T4
//  / \                             / \
// T2   T3                         T1  T2

// Right Right imbalance
//   z                                y
//  /  \                            /   \
// T1   y     Left Rotate(z)       z      x
//     /  \   - - - - - - - ->    / \    / \
//    T2   x                     T1  T2 T3  T4
//        / \
//       T3  T4

// Right left imbalance
//    z                            z                            x
//   / \                          / \                          /  \
// T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
//     / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
//    x   T4                      T2   y                  T1  T2  T3  T4
//   / \                              /  \
// T2   T3                           T3   T4

//   10 (x)                  20
//     \                    /  \
//      20 (y)      =>    10    30
//     /  \               /
//    T2   30            T2

namespace exemplar
{
    template <class T> class AVLTreeNode
    {
    public:
        AVLTreeNode(const T& value) : value(value)
        {
        }

        AVLTreeNode* insert(const T& newValue)
        {
            AVLTreeNode* newNode = this;
            if (newValue == value) {
                return this;
            }
            else if (newValue < value) {
                // left
                if (left == nullptr) {
                    left = new AVLTreeNode(newValue);
                }
                else {
                    left = left->insert(newValue);
                }
            }
            else {
                // right
                if (right == nullptr) {
                    right = new AVLTreeNode(newValue);
                }
                else {
                    right = right->insert(newValue);
                }
            }

            height = 1 + std::max(left ? left->height : 0, right ? right->height : 0);

            int balance = getBalance();
            if (left && balance > 1 && newValue < left->value) {
                return rightRotate();
            }
            if (right && balance < -1 && newValue > right->value) {
                return leftRotate();
            }
            if (left && balance > 1 && newValue > left->value) {
                left = left->leftRotate();
                return rightRotate();
            }
            if (right && balance < -1 && newValue < right->value) {
                right = right->rightRotate();
                return leftRotate();
            }

            return newNode;
        }

        int getBalance()
        {
            return (left ? left->height : 0) - (right ? right->height : 0);
        }

        AVLTreeNode* rightRotate()
        {
            AVLTreeNode* y = this;
            AVLTreeNode* x = y->left;
            AVLTreeNode* T2 = x->right;
            x->right = y;
            y->left = T2;

            y->height = 1 + std::max(y->left ? y->left->height : 0, y->right ? y->right->height : 0);
            x->height = 1 + std::max(x->left ? x->left->height : 0, x->right ? x->right->height : 0);

            return x;
        }

        AVLTreeNode* leftRotate()
        {
            AVLTreeNode* x = this;
            AVLTreeNode* y = x->right;
            AVLTreeNode* T2 = y->left;
            y->left = x;
            x->right = T2;

            x->height = 1 + std::max(x->left ? x->left->height : 0, x->right ? x->right->height : 0);
            y->height = 1 + std::max(y->left ? y->left->height : 0, y->right ? y->right->height : 0);
            
            return y;
        }

        void contentsPreOrder(vector<T>& v)
        {
            // root, left, right
            v.push_back(value);            
            if (left != nullptr) {
                left->contentsPreOrder(v);
            }
            if (right != nullptr) {
                right->contentsPreOrder(v);
            }
        }

        int height = 1;
        T value;
        AVLTreeNode* left = nullptr;
        AVLTreeNode* right = nullptr;
    };

    void avltree_example();
}
