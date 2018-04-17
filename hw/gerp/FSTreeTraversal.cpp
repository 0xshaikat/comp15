// Shaikat Islam
// COMP15
// Phase I
// 17-04-2018

#include <iostream>
#include "DirNode.h"
#include "FSTree.h"
#include <string>
using namespace std;

//function defs
void path_print(string);
void preorder_print(DirNode*, string);

//int main
//Purpose: run program
//Returns: int
//Parameters: (int argc, char *argv[])
int main(int argc, char *argv[])
{
    // if num of arguments is not exactly 2, exit program
    if (argc != 2)
    {
        return 0;
    }
    //print the paths and return 0
    else
    {
        path_print(argv[1]);
        return 0;
    }
}// end main

//void path_print
//Purpose: make an FSTree and call a helper
//Returns: void
//Parameters: string
void path_print(string directory)
{
    FSTree fs = FSTree(directory);
    preorder_print(fs.get_root(), directory);
}//end path_print

//void preorder_print
//Purpose: traverse through dirs in preorder and print paths
//Returns: void
//Parameters: (DirNode*, string)
void preorder_print(DirNode *dir, string s)
{
    int num_files = dir->num_files();
    //print final path for file in a DirNode (should be run after last recursive
    //run)
    if (num_files > 0)
    {
        //print final paths for a DirNode
        for (int i = 0; i < num_files; i++)
        {
            cout << s << "/" << dir->get_file(i) << endl;
        }// end for
    }// end if

    //recurse through all the other dirs and subdirectories
    int num_sub_dir = dir->num_subdirs();
    string s_1 = "";

    //go through other subdirectories
    if (num_sub_dir > 0)
    {
        //traverse through subdirs
        for (int x = 0; x < num_sub_dir; x++)
        {
            DirNode* sub = dir->get_subdir(x);
            s_1 = s + "/" + sub->get_name();
            preorder_print(sub, s_1);
        }// end for
    }// end if
}// end preorder_print
