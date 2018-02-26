/*
 * BinarySearchTree.h
 *
 * Interface for derived class BST
 * Inherits from Binary Tree
 *
 * Gloria Gaynor wants you to
 *
 * Don't be afraid.
 *
 * Don't be petrified.
 *
 * Come back from outer space.
 */

#include "BinaryTree.h"

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

// Prototypes for recursive wrapper functions
void insert_bst(BinaryNode *&, BinaryNode::TreeItem);
BinaryNode * remove_item_bst(BinaryNode *&, BinaryNode::TreeItem);
void find_item_bst(BinaryNode *, BinaryNode::TreeItem &, bool &);
BinaryNode * find_minimum_bst(BinaryNode *&);

class BinarySearchTree : public BinaryTree
{

public:
    BinarySearchTree();
    // BT has a virtual destructor
    // so we write our own for BST
    ~BinarySearchTree();

    // copy constructor
    BinarySearchTree(const BinarySearchTree &);
    // assignment operator
    BinarySearchTree & operator = (const BinarySearchTree &);

    // overridden from BinaryTree
    void insert_item(BinaryNode::TreeItem);
    void remove_item(BinaryNode::TreeItem);
    void find_item(BinaryNode::TreeItem &, bool &) const;

};

#endif
