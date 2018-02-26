/*
 * BinaryTree.cpp
 *
 * Implementation for base class BinaryTree
 * Starter code for Project 1
 *
 * COMP15
 * Spring 2018
 *
 * What did the Binary Tree traversal get a dinner?
 *
 * The pre-fix menu!
 */

#include <cstddef>
#include "Queue.h"
#include "Tree.h"
#include "BinaryTree.h"

// Constructor
BinaryTree::BinaryTree()
{
    root = NULL;
}

// Destructor
BinaryTree::~BinaryTree()
{
    destroy(root);
}

// Copy Constructor
BinaryTree::BinaryTree(const BinaryTree &b)
{
    //if root is null, copy constructor
    if (b.root ==  NULL)
    {
        root = NULL;
    }//end if
    //traverse binary tree and make copy pre-order
    else
    {
        root = copy_tree(b.root);
    }//end else
}//end copy constructor

// Assignment Operator
BinaryTree & BinaryTree::operator = (const BinaryTree &b)
{
    // self-assignment check
    if (this != &b)
    {
        // delete if it already exists
        destroy(root);
    }
    // copy tree
    root = copy_tree(b.root);
    // return this
    return *this;
}//end assignment operator

// overloaded << operator to print tree
void BinaryTree::print(ostream &output) const
{
    (root->info).print(output);
    output << "\n";
    int h = height(root);
    output << "Height: " << h;
    output << "\n";
    int n = count_nodes(root);
    output << "Number of nodes: " << n;
    output << "\n";
    int l = count_leaves(root);
    output << "Number of leaves: " << l;
    output << "\n";
}//end <<

// Function print_root (const)
// prints the root of a tree
void BinaryTree::print_root(ostream &output) const
{
    (root->info).print(output);
}//end print_root

// Function is_full (const)
// Determines whether or not a tree is full
bool BinaryTree::is_full() const
{
    try // allocate new memory
    {
        BinaryNode *newnode = new BinaryNode();
        delete newnode;
        return false;
    }
    catch (bad_alloc exception) // if it doesn't work, the tree is full
    {
        return true;
    }
}//end is_full()

// Function is_empty (const)
// Returns true if tree is empty, false otherwise
bool BinaryTree::is_empty() const
{
    if (root == NULL)
    {
        return true;
    }
    return false;
}//end is_empty()

// Function get_length (const)
// Counts the total number of nodes in the tree
int BinaryTree::get_length() const
{
    return count_nodes(root);
}

// Function get_height (const)
// Returns depth of deepest node in tree
int BinaryTree::get_height() const
{
    return height(root);
}//end get_height

// Function avg_age (const)
// Returns average age of all castaways in tree
int BinaryTree::avg_age() const
{
    return sum(root) / count_nodes(root);
}//end avg_age

// Inorder traversal
void BinaryTree::inorder(ostream &out) const
{
    print_inorder(root, out);
}

// preorder traversal
void BinaryTree::preorder(ostream &out) const
{
    print_preorder(root, out);
}

// postorder traversal
void BinaryTree::postorder(ostream &out) const
{
    print_postorder(root, out);
}

// Function insert_item
// Checks for fullness, throws exception if necessary
// insert item into next open slot
void BinaryTree::insert_item(BinaryNode::TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bt(root, item);
}

// Function num_leaves (const)
// Returns number of leaves in a tree
int BinaryTree::num_leaves() const
{
    return count_leaves(root);
}//end num_leaves

// Function find_item
// finds the given item using queue as auxiliary structure
void BinaryTree::find_item(BinaryNode::TreeItem &item, bool & found) const
{
    find_bt(root, item, found);
}

// Function remove_item
// Checks for empty tree, throws exception if necssary
// remove item, if found
void BinaryTree::remove_item(BinaryNode::TreeItem item)
{
    if (is_empty())
        throw EmptyTree();
    else
    {
        bool found = false;
        find_item(item, found);
        if (found)
            remove_bt(root, item);
    }
}

// Return the item at the deepest left node
// (Would come first in an in-order traversal)
// Throws exception if tree is empty
BinaryNode::BinaryNode::TreeItem BinaryTree::get_leftmost() const
{
    return return_leftmost(root);
}

// Return the item at the deepest right node
// (Would come second in a pre-order traversal)
// Throws exception if tree is empty
BinaryNode::BinaryNode::TreeItem BinaryTree::get_rightmost() const
{
    return return_rightmost(root);
}

/* Definitions for Recursive Wrapper Functions */

// Function destroy (wrapper)
// Used by destructor and = operator
// Follows postfix order, deletes nodes one by one
void destroy(BinaryNode *&tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

// Recursively counts the total number of nodes in the tree
int count_nodes(BinaryNode *tree)
{
    if (tree == NULL)
        return 0;
    else
        return count_nodes(tree->left) + count_nodes(tree->right) + 1;
}

// Print in  order
void print_inorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_inorder(tree->left, out);
        tree->info.print(out);
        print_inorder(tree->right, out);
    }
}

// Print in prefix order
void print_preorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        tree->info.print(out);
        print_preorder(tree->left, out);
        print_preorder(tree->right, out);
    }
}

// Print in postfix order
void print_postorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_postorder(tree->left, out);
        print_postorder(tree->right, out);
        tree->info.print(out);
    }
}

// Function insert_bt (wrapper)
// Params: BinaryNode reference, BinaryNode::TreeItem
// Returns: void
// Does: Finds next open spot using a queue
//       allocates a new BinaryNode and sets
//       its info to the given tree
void insert_bt(BinaryNode *&tree, BinaryNode::TreeItem item)
{
    // enqueue and dequeue until empty
    BinaryNode *temp = NULL;
    BinaryNode *node = new BinaryNode;
    node->info = item;
    node->left = NULL;
    node->right = NULL;
    if (tree == NULL)
    {
        tree = node;
        return;
    }

    Queue q;
    q.enqueue(tree);
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->left != NULL)
        {
            q.enqueue(temp->left);
        }
        else
        {
            temp->left = node;
            return;
        }
        if (temp->right != NULL)
        {
            q.enqueue(temp->right);
        }
        else
        {
            temp->right = node;
            return;
        }
    }
}

// Function find_bt (not a member function)
// Parameters: BinaryNode (root), BinaryNode::TreeItem reference, bool reference
// Returns: void
// Does: Uses an auxiliary queue to iterate through each node
//       until the item is found. Updates the item reference with
//       the one actually found, and bool reference with true/false.
void find_bt(BinaryNode *tree, BinaryNode::TreeItem &item, bool &found)
{
    found = false;
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    while (!q.is_empty())
    {
        BinaryNode *node;
        q.dequeue(node);
        if (node->info == item)
        {
            item = node->info;
            found = true;
            return;
        }
        if (node->left != NULL)
            q.enqueue(node->left);
        if (node->right != NULL)
            q.enqueue(node->right);
    }
}

// Function remove_bt (wrapper)
// Parameters: BinaryNode reference (root), BinaryNode::TreeItem to remove
// Returns: void
// Does: Uses an auxiliary queue to find the deepest item
//       swaps one to delete with deepest item
//       deletes deepest item
void remove_bt(BinaryNode *&tree, BinaryNode::TreeItem item)
{
    if (tree == NULL)
    {
        return;
    }

    Queue q;
    q.enqueue(tree);

    BinaryNode *deep = NULL, *keynode = NULL;

    while (!q.is_empty())
    {
        q.dequeue(deep);
        if (deep->info == item)
            keynode = deep;
        if (deep->left != NULL)
            q.enqueue(deep->left);
        if (deep->right != NULL)
            q.enqueue(deep->right);
    }

    BinaryNode::TreeItem val = deep->info;
    delete_deepest(tree, deep);
    if (deep != keynode)
        keynode->info = val;
}

// Delete deepest node in the tree
// Helper function for remove
void delete_deepest(BinaryNode *&tree, BinaryNode *&deepnode)
{
    Queue q;
    q.enqueue(tree);

    BinaryNode *temp;
    while (!q.is_empty())
    {
        q.dequeue(temp);
        if (temp->right != NULL)
        {
            if (temp->right->info == deepnode->info)
            {
                temp->right = NULL;
                delete deepnode;
                return;
            }
            else
                q.enqueue(temp->right);
        }
        if (temp->left != NULL)
        {
                if (temp->left->info == deepnode->info)
                {
                    temp->left = NULL;
                    delete deepnode;
                    return;
                }
                else
                    q.enqueue(temp->left);
        }
    }
}

// Function return_leftmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: BinaryNode::TreeItem, the info in the deepest left node
// Throws exception if tree is empty, it has no leftmost node
BinaryNode::TreeItem return_leftmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->left == NULL)
        return tree->info;
    else
       return return_leftmost(tree->left);
}

// Function return_rightmost(wrapper)
// Params: BinaryNode *, the tree
// Returns: BinaryNode::TreeItem, the info in the deepest rightmost node
// Throws exception if tree is empty, it has no rightmost node
BinaryNode::TreeItem return_rightmost(BinaryNode *tree)
{
    if (tree == NULL)
        throw EmptyTree();
    else if (tree->right == NULL)
        return tree->info;
    else
        return return_rightmost(tree->right);
}

// Function copy_tree(wrapper)
// Params: Original BinaryNode *
// Returns: void
// Copies tree for constructor
BinaryNode * copy_tree(BinaryNode *node)
{
    //check for NULL
    if (node == NULL)
    {
        return NULL;
    }//end if
    else
    {
        //copies data to new node pre_order
        BinaryNode *new_node = new BinaryNode();
        new_node->info = node->info;
        new_node->left = copy_tree(node->left);
        new_node->right = copy_tree(node->right);
        return new_node;
    }//end else
}//end copy_tree

// Function count_leaves (wrapper)
// Counts number of leaves in tree, passes to num_leaves()
int count_leaves(BinaryNode *tree)
{
    if (tree == NULL)
    {
        return 0;
    }//end if
    else if (tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }//end else
    else
    {
        return count_leaves(tree->left) + count_leaves(tree->right);
    }//end else
}//end count_leaves

// Function height(BinaryNode *) (wrapper)
// Returns depth of innermost BinaryNode in tree
int height(BinaryNode *tree)
{
    if (tree == NULL)
    {
        return 0;
    }//end if
    else
    {
        //recursively get height of each subtree
        int lh = height(tree->left);
        int rh = height(tree->right);
        //return bigger one
        if (lh > rh)
        {
            return (lh + 1);
        }//end if
        else
        {
            return (rh + 1);
        }//end else
    }//end else
}//end height

// Function sum(BinaryNode *) (wrapper)
// Returns sum of ages of castaways in tree
int sum(BinaryNode *tree)
{
    if (tree == NULL)
    {
        return 0;
    }//end if
    else
    {
        int total = tree->info.get_age();
        if (tree->left != NULL)
        {
            total += sum(tree->left);
        }//end if
        if (tree->right != NULL)
        {
            total += sum(tree->right);
        }//end if
        return total;
    }
}//end average
