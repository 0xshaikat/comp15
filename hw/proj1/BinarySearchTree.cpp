/*
 * Shaikat Islam
 * COMP15
 * 26-02-18
 * Project 1
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

}//end constructor

// Destructor requires no action, base class handles it
BinarySearchTree::~BinarySearchTree()
{

}//end destructor

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &bst)
{
    // if root is null, so will the copy of the root
    if (bst.root == NULL)
    {
        root = NULL;
    }//end if
    // deep copy
    else
    {
        root = copy_tree(bst.root);
    }//end else
}//end copy constructor

// assignment operator
BinarySearchTree & BinarySearchTree::operator = (const BinarySearchTree &bst)
{
    // so long as object copied is not equal to the referenced bst
    if (this != &bst)
    {
        destroy(root);
    }//end if
    // then copy
    root = copy_tree(bst.root);
    return *this;
}//end assignment operator

// Function to insert into a BST
// Throws exception if full
// Calls wrapper function for recursion
void BinarySearchTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bst(root, item);
}// end insert_item

// Function to remove into a BST
// Throws exception if empty
// Calls wrapper function for recursion
void BinarySearchTree::remove_item(TreeItem item)
{
    //if tree empty, don't remove
    if (is_empty())
    {
        throw EmptyTree();
    }//end if
    // if item is found then remove
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

// Function to find item in a BST
// Throws exception if empty
// Calls wrapper function for recursion
void BinarySearchTree::find_item(TreeItem &item, bool &b) const
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
void insert_bst(BinaryNode *&tree, TreeItem item)
{
    //make root the item
    if (tree == NULL)
    {
        tree = new BinaryNode; // this part is why pass by ref
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }//end if
    //insert to left
    else if (item < tree->info)
    {
        insert_bst(tree->left, item);
    }//end else if
    //insert to right
    else if (item > tree->info)
    {
        insert_bst(tree->right, item);
    }//end else if
}// end insert_bst

// Wrapper function for remove
BinaryNode * remove_item_bst(BinaryNode *&tree, TreeItem item)
{
    //return NULL if item to remove is root
    if (tree == NULL)
    {
        return NULL;
    }//end if
    //CASE ONE: 0 or 2 children
    //subcase one: less than root
    if (item < tree->info)
    {
        tree->left = remove_item_bst(tree->left, item);
    }//end if
    //subcase two: greater than root
    else if (item > tree->info)
    {
        tree->right = remove_item_bst(tree->right, item);
    }//end else if
    //CASE TWO: one of children is NULL
    else
    {
        if (tree->left == NULL)
        {
            BinaryNode *temp = tree->right;
            delete tree;
            return temp;
        }// end if
        else if (tree->right == NULL)
        {
            BinaryNode *temp = tree->left;
            delete tree;
            return temp;
        }// end else if
        // recursively remove based on predecessor
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
void find_item_bst(BinaryNode *tree, TreeItem &item, bool &b)
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
