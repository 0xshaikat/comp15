#include <cstddef>
#include "BinarySearchTree.h"


// Member function definitions
BinarySearchTree::BinarySearchTree()
{
    // no action required, base class also called
}

BinarySearchTree::~BinarySearchTree()
{
    // no action required, base class also called
}

// Overriding the insert from base class
// Calls wrapper to recursively insert
void BinarySearchTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert_bst(root, item);
}

// Function insert_bst (wrapper)
// Paramaters: BinaryNode pointer reference, TreeItem to insert
// Returns: void
// Does: Finds correct position in tree for TreeeItem
//       allocates new BinaryNode and new element becomes
//       a leaf. Pointer ref required because we're modifying
//       the BinaryNode * tree itself
void insert_bst(BinaryNode *&tree, TreeItem item)
{
    if (tree == NULL)
    {
        tree = new BinaryNode; 
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    }
    else if (item < tree->info)
    {
        insert_bst(tree->left, item);
    }
    else    
    {
        insert_bst(tree->right, item);
    }
}

