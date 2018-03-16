/*
 * BinarySearchTree.h
 *
 * COMP15
 * Spring 2018
 * Derived class for a BST
 *
 */

#include "BinaryTree.h"

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

// Prototypes for recursive wrapper functions
void insert_bst(BinaryNode *&, TreeItem);

class BinarySearchTree : public BinaryTree
{

public:
    // BT has a constructor
    // both get called
    BinarySearchTree();

    // BT has a virtual destructor
    // so we write our own for BST
    // Both get called when BST goes out of scope
    ~BinarySearchTree();

    // Rule of 3
    // Copy constructor and assignment operator
    // WILL go here, when you do them for Proj1
    // not needed for the lab

    // overwritten from BinaryTree
    void insert_item(TreeItem);
};

#endif
