/*
 * BinarySearchTree.cpp
 *
 * COMP15
 * Spring 2018
 *
 * Implementation for BST class.
 * Inherits from BinaryTree class.
 *
 * Beyonce also wants you to be a SURVIVOR.
 *
 * You thought you'd be stressed but you're chillin'.
 */

#include <cstddef>
#include "BinarySearchTree.h"

// Member function definitions
// Constructor requires no action, base class handles it
BinarySearchTree::BinarySearchTree()
{

}

// Destructor requires no action, base class handles it
BinarySearchTree::~BinarySearchTree()
{

}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &bst)
{
    if (bst.root == NULL)
    {
        root = NULL;
    }
    else
    {
        root = copy_tree(bst.root);
    }
}//end copy constructor

// assignment operator
BinarySearchTree & BinarySearchTree::operator = (const BinarySearchTree &bst)
{
    if (this != &bst)
    {
        destroy(root);
    }
    root = copy_tree(bst.root);
    return *this;
}//end assignment operator

// Function to insert into a BST
// Throws exception if full
// Calls wrapper function for recursion
void BinarySearchTree::insert_item(BinaryNode::TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bst(root, item);
}

void BinarySearchTree::remove_item(BinaryNode::TreeItem item)
{
    if (is_empty())
    {
        throw EmptyTree();
    }//end if
    else
    {
        bool found = false;
        find_item(item, found);
        if (found)
        {
            root = remove_item_bst(root, item);
        }//end if
    }//end else
}//end remove_item

void BinarySearchTree::find_item(BinaryNode::TreeItem &item, bool &b) const
{
    if (is_empty())
    {
        throw EmptyTree();
    }//end if
    else
    {
        find_item_bst(root, item, b);
    }//end else
}//end find_item

// Wrapper function for insert
void insert_bst(BinaryNode *&tree, BinaryNode::TreeItem item)
{
    if (tree == NULL)
    {
        tree = new BinaryNode; // this part is why pass by ref
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }//end if
    else if (item < tree->info)
    {
        insert_bst(tree->left, item);
    }//end else if
    else if (item > tree->info)
    {
        insert_bst(tree->right, item);
    }//end else if
}

// Wrapper function for remove
BinaryNode * remove_item_bst(BinaryNode *&tree, BinaryNode::TreeItem item)
{
    if (tree == NULL)
    {
        return NULL;
    }//end if
    if (item < tree->info)
    {
        tree->left = remove_item_bst(tree->left, item);
    }//end if
    else if (item > tree->info)
    {
        tree->right = remove_item_bst(tree->right, item);
    }//end else if
    else
    {
        if (tree->left == NULL)
        {
            BinaryNode *temp = tree->right;
            delete tree;
            return temp;
        }
        else if (tree->right == NULL)
        {
            BinaryNode *temp = tree->left;
            delete tree;
            return temp;
        }
        BinaryNode *temp = find_minimum_bst(tree->right);
        tree->info = temp->info;
        tree->right = remove_item_bst(tree->right, temp->info);
    }//end else
    return tree;
}//end remove_item_bst

// Wrapper function for find_minimum
BinaryNode * find_minimum_bst(BinaryNode *& tree)
{
    if (tree == NULL)
    {
        return tree;
    }//end if
    if (tree->left != NULL)
    {
        return find_minimum_bst(tree->left);
    }//end if
    return tree;
}//end find_minimum_bst

// Wrapper function for find_item
void find_item_bst(BinaryNode *tree, BinaryNode::TreeItem &item, bool &b)
{
    if (tree == NULL)
    {
        b = false;
        return;
    }//end if
    if (tree->info == item)
    {
        b = true;
        return;
    }
    if (tree->info < item)
    {
        find_item_bst(tree->right, item, b);
    }//end if
    else
    {
        find_item_bst(tree->left, item, b);
    }//end else
}//end find_item_bst
