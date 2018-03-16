/*
 * BinaryTree.h
 *
 * COMP15
 * Spring 2018
 * 
 * Make like a tree...
 * and get outta here.
 */

#include <iostream>
#include "Queue.h"
using namespace std;

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

class FullTree : public exception 
{
public:
    const char *what() const throw() { return "Full Tree!\n"; }
};

class EmptyTree : public exception
{
public:
    const char *what() const throw() { return "Empty tree!!\n"; }
};

// Prototypes for recursive wrapper functions
void destroy(BinaryNode *);
void print_inorder(BinaryNode *, ostream &);
void print_preorder(BinaryNode *, ostream &);
void print_postorder(BinaryNode *, ostream &);
void insert(BinaryNode *&, TreeItem);

class BinaryTree
{
public:
    BinaryTree();

    // destructor is made virtual so that we will
    // be forced to invoke the derived class's version
    // if it exists
    virtual ~BinaryTree();

    // Rule of 3: copy constructor and = operator
    // should be here, but that'll be for homework!

    // implemented in base class, and
    // inherited as-is by all derived classes
    void inorder(ostream &) const;
    void preorder(ostream &) const;
    void postorder(ostream &) const;
    bool is_full() const;

    // virtual function is defined in base class,
    // overridden in derived class
    virtual void insert_item(TreeItem);

protected:
    BinaryNode *root;
};

#endif
