#include <cstddef>
#include "Queue.h"
#include "BinaryTree.h"

// BT constructor
BinaryTree::BinaryTree()
{
    root = NULL;
}

// BT destructor
BinaryTree::~BinaryTree()
{
    destroy(root);
}

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

// insert item in next open slot
void BinaryTree::insert_item(TreeItem item)
{
    if (is_full())
        throw FullTree();
    else
        insert(root, item);
}

// check for full tree
bool BinaryTree::is_full() const
{
    try
    {
        BinaryNode *node = new BinaryNode;
        delete node;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

// Definitions for Recursive Wrapper Functions

// Wrapper to recursively delete all nodes
// Input: BinaryNode pointer reference
//        (pointer ref because the actual
//        pointer needs to be modified, not just
//        the thing it points too)
void destroy(BinaryNode *tree)
{
    if (tree != NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
    }
}

// Wrapper to print in-order traversal
void print_inorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_inorder(tree->left, out);
        out << tree->info << " ";
        print_inorder(tree->right, out);
    }
} 

// Wrapper to print pre-order traversal
void print_preorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        out << tree->info << " ";
        print_preorder(tree->left, out);
        print_preorder(tree->right, out);
    }
} 

// Wrapper to print post-order traversal
void print_postorder(BinaryNode *tree, ostream &out)
{
    if (tree != NULL)
    {
        print_postorder(tree->left, out);
        print_postorder(tree->right, out);
        out << tree->info << " ";
    }
}

// Wrapper to recursively insert
// Input: BinaryNode * reference and TreeItem
// Returns: void
// Does: Inserts the given item at the next
//       open slot, top to bottom and left to right.
//       Takes a pointer ref because it needs to
//       modify the given tree.
void insert(BinaryNode *&tree, TreeItem item)
{
    // New item to insert always goes in a leaf
    BinaryNode *temp = NULL;
    BinaryNode *node;

    node = new BinaryNode;
    node->info = item;
    node->left = NULL;
    node->right = NULL;
 
    // Actual insert!
    if (tree == NULL)
    {
        tree = node; 
        return;
    }
    
    // Auxiliary queue maintains the
    // nodes we're searching through to find
    // the empty slot
    Queue q;
    q.enqueue(tree);
    while (!q.is_empty())
    {
        temp = q.dequeue();
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



