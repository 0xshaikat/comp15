#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Survivor.h"

//FUNCTION DEFINITIONS:
void populate_trees(BinaryTree *, BinaryTree *);
BinaryTree * determine_round_one(BinaryTree *, BinaryTree *);
void determine_round_two(BinaryTree *);

int main()
{
    //seed rand function
    srand(time(0));
    BinaryTree *bt = new BinaryTree;
    BinaryTree *bst = new BinarySearchTree;
    populate_trees(bt, bst);
    BinaryTree *winner = determine_round_one(bt, bst);
    cout << endl;
    determine_round_two(winner);
    delete bt;
    delete bst;
}//end main

//FUNCTIONS
void populate_trees(BinaryTree *bt, BinaryTree *bst)
{
    int r = rand() % 2;
    ifstream cast;
    ifstream stow;
    cast.open("castaways.txt");
    stow.open("stowaways.txt");
    if (!cast)
    {
        cerr << "Unable to open file 'castaways.txt'.\n";
    }
    if (!stow)
    {
        cerr << "Unable to open file 'stowaways.txt'.\n";
    }

    //check for line length in files to populate survivor pointers
    int cast_c = 0;
    int stow_c = 0;
    string c;
    string s;

    while(getline(cast, c))
    {
        if (c != "-1")
        {
            cast_c++;
        }//end if
    }//end while

    while(getline(stow, s))
    {
        if (s != "-1")
        {
            stow_c++;
        }//end if
    }//end while
    cast_c--;
    stow_c--;

    //pointers for survivors
    Survivor *castaway = new Survivor[cast_c];
    Survivor *stowaway = new Survivor[stow_c];

    //populate bt with castaways and bst with stowaways
    if (r == 0)
    {
        for (int i = 0; i < cast_c; i++)
        {
            castaway[i].generate_n_survivor(cast, i);
            bt->insert_item(castaway[i]);
        }//end for
        for (int i = 0; i < stow_c; i++)
        {
            stowaway[i].generate_n_survivor(stow, i);
            bst->insert_item(stowaway[i]);
        }//end for
    }//end if
    //do the reverse
    else
    {
        for (int i = 0; i < cast_c; i++)
        {
            castaway[i].generate_n_survivor(cast, i);
            bst->insert_item(castaway[i]);
        }//end for
        for (int i = 0; i < stow_c; i++)
        {
            stowaway[i].generate_n_survivor(stow, i);
            bt->insert_item(stowaway[i]);
        }//end for
    }//end else

    // delete memory
    delete []castaway;
    delete []stowaway;
}//end populate_trees

// function to get round one
BinaryTree * determine_round_one(BinaryTree *bt, BinaryTree *bst)
{
    if (bt->num_leaves() < bst->num_leaves())
    {
        cout << "Loser had " << bst->num_leaves() << " leaves\n";
        cout << "ROUND ONE WINNER: BT\n";
        ostream & objOstream = cout;
        bt->print(objOstream);
        return bt;
    }//end if
    else if (bst->num_leaves() < bt->num_leaves())
    {
        cout << "Loser had " << bt->num_leaves() << " leaves\n";
        cout << "ROUND ONE WINNER: BST\n";
        ostream & objOstream = cout;
        bst->print(objOstream);
        return bst;
    }//end else if
    else
    {
        cout << "Loser had " << bst->num_leaves() << " leaves\n";
        cout << "ROUND ONE WINNER: BT\n";
        ostream & objOstream = cout;
        bt->print(objOstream);
        return bt;
    }//end else if
}//end determine_round_one

// function to get round two
void determine_round_two(BinaryTree *bt)
{
    int n = 0;
    int m = 0;
    while (bt->get_length() != 1)
    {
        cout << "Average age this round " << bt->avg_age() << endl;
        TreeItem leftmost = bt->get_leftmost();
        TreeItem rightmost = bt->get_rightmost();
        n = fabs(leftmost.get_age() - bt->avg_age());
        m = fabs(rightmost.get_age() - bt->avg_age());
        if (n > m)
        {
            cout << "Voted off the island:\n";
            ostream & objOstream = cout;
            leftmost.print(objOstream);
            bt->remove_item(leftmost);
            cout << endl;
        }
        else if (n < m)
        {
            cout << "Voted off the island:\n";
            ostream & objOstream = cout;
            rightmost.print(objOstream);
            bt->remove_item(rightmost);
            cout << endl;
        }
        else if (n == m)
        {
            cout << "Voted off the island:\n";
            ostream & objOstream = cout;
            leftmost.print(objOstream);
            bt->remove_item(leftmost);
            cout << endl;
        }
    }//end while
    cout << "WINNING SURVIVOR:\n";
    ostream & objOstream = cout;
    TreeItem win = bt->get_rightmost();
    win.print(objOstream);
}//end determine_round_two
