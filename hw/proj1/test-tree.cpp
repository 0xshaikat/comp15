#include <iostream>
#include <string>
#include <fstream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Survivor.h"
using namespace std;

// Test functions for all BT and BST operations not covered in other
// test drivers
void populate(BinaryTree *);
void test_num_leaves(BinaryTree *);
void test_height(BinaryTree *);
void test_average(BinaryTree *);
void test_print(BinaryTree *);
void test_print_root(BinaryTree *);
void test_remove_item(BinaryTree *);
void test_find_item(BinaryTree *);

int main()
{
    BinaryTree *BST = new BinarySearchTree;
    populate(BST);
    test_num_leaves(BST);
    test_height(BST);
    test_average(BST);
    test_print(BST);
    test_print_root(BST);
    test_remove_item(BST);
    delete BST;
    cout << endl;
    cout << endl;
    cout << "Testing on Binary Tree now...\n";
    cout << endl;
    BinaryTree *BT = new BinaryTree;
    populate(BT);
    test_num_leaves(BT);
    test_height(BT);
    test_average(BT);
    test_print(BT);
    test_print_root(BT);
    test_remove_item(BT);
    delete BT;
}//end main

void populate(BinaryTree *bt)
{
    Survivor *slist = new Survivor[30];
    for (int i = 0; i < 30; i++)
    {
        cout << "Populating tree from file...\n";
        ifstream in;
        in.open("castaways.txt");
        slist[i].generate_n_survivor(in, i);
        bt->insert_item(slist[i]);
    }//end for
    if (bt->get_length() == 30)
    {
        cout << "POPULATE SUCCESS\n";
        cout << endl;
    }
    else
    {
        cout << "POPULATE FAIL\n";
        cout << endl;
    }//end if
    delete []slist;
}//end populate

void test_num_leaves(BinaryTree *bt)
{
    cout << "num leaves: "<< bt->num_leaves() << endl;
}
void test_height(BinaryTree *bt)
{
    cout << "height: " << bt->get_height() << endl;
}

void test_average(BinaryTree *bt)
{
    cout << "average age: " << bt->avg_age() << endl;
    cout << endl;
}

void test_print(BinaryTree *bt)
{
    ostream & objOstream = cout;
    cout << "Testing the print function...\n";
    bt->print(objOstream);
    cout << endl;
}

void test_print_root(BinaryTree *bt)
{
    ostream & objOstream = cout;
    cout << "Testing print root function...:\n";
    bt->print_root(objOstream);
    cout << endl;
}

void test_remove_item(BinaryTree *bt)
{
    Survivor s;
    bt->insert_item(s);
    bool is_there;
    bt->find_item(s, is_there);
    cout << "Testing remove...\n";
    cout << "Before remove:\n";
    if (is_there)
    {
        cout << "OBJECT IS IN TREE\n";
    }
    else
    {
        cout << "FAIL\n";
    }//end else
    bt->remove_item(s);
    bt->find_item(s, is_there);
    cout << "After remove...\n";
    if (!is_there)
    {
        cout << "OBJECT IS NOT IN TREE\n";
    }//end if
    else
    {
        cout << "FAIL\n";
    }//end else
    //check remove
}//end test_remove_item
