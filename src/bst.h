#pragma once

#include <vector>

using namespace std;

// BST
// A simple, unbalanced binary search tree.
// Complexity:
// Insert & find O(logN) best case (evenly distrivuted range of inserted values)
// O(N), worst case (presorted values inserted)

namespace exemplar
{
    template <class T> class BSTNode
    {
    public:
        BSTNode(const T& value) : value(value)
        {
        }

        BSTNode* insert(const T& newValue)
        {
            if (newValue == value) {
                return nullptr;
            }
            else if (newValue < value) {
                // left
                if (left == nullptr) {
                    left = new BSTNode(newValue);
                    return left;
                }
                else {
                    return left->insert(newValue);
                }
            }
            else {
                // right
                if (right == nullptr) {
                    right = new BSTNode(newValue);
                    return right;
                }
                else {
                    return right->insert(newValue);
                }
            }
        }

        void contentsInOrder(vector<T>& v)
        {
            // left, root, right
            if (left != nullptr) {
                left->contentsInOrder(v);
            }
            v.push_back(value);
            if (right != nullptr) {
                right->contentsInOrder(v);
            }
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

        void contentsPostOrder(vector<T>& v)
        {
            // left, right, root
            if (left != nullptr) {
                left->contentsPostOrder(v);
            }
            if (right != nullptr) {
                right->contentsPostOrder(v);
            }
            v.push_back(value);            
        }

        int getDepth(int level = 1)
        {
            int leftDepth = 0;
            int rightDepth = 0;
            if (left == nullptr && right == nullptr) {
                return level;
            }
            if (left != nullptr) {
                leftDepth = left->getDepth(level + 1);
            }
            if (right != nullptr) {
                rightDepth = right->getDepth(level + 1);
            }
            return std::max(leftDepth, rightDepth);
        }

    private:
        T value;
        BSTNode<T>* left = nullptr;
        BSTNode<T>* right = nullptr;
    };

    void bst_example();
}
