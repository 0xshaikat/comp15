/*
 * Shaikat Islam
 * tufts-major.cpp
 *
 * COMP15
 * Spring 2018
 * Lab 5
 *
 * Print out all the ways you could complete
 * the comp sci major (core courses only)
 */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "LinkedList.h"
using namespace std;

const int NUM_CORE = 7;
const int NUM_PERM = 5040;

void read_majors_from_file(char *, LinkedList<string>[]);
void check_legitimacy(char *);
void print_perm(LinkedList<string>);

// Get arguments from the command line first!
// Expected usage: ./major tufts-major-core.txt all-possible-order.txt
int main(int argc, char *argv[])
{
    LinkedList<string> dependencies[NUM_CORE];
    string arg_0 = "./major";
    string arg_1 = "tufts-major-core.txt";
    string arg_2 = "all-possible-orders.txt";
    if ((argv[0] != arg_0) || (argv[1] != arg_1) || (argv[2] != arg_2) ||
        (argc != 3))
    {
        cout << "The arguments that this program requires are: "
             << "\n" << arg_0 << " " << arg_1 << " " << arg_2
             << "\n";
        cout << "The program will exit; please try again.\n";
        return 0;
    }
    else
    {
        // Note that this function call passes argv[1]
        // that's second command-line argument, tufts-major-core.txt
        read_majors_from_file(argv[1], dependencies);

        //read in file of all possible permutations
        check_legitimacy(argv[2]);
        return 0;
    }
}

// Function read_majors_from_file
// Input: file name, array of Linked Lists
// Returns: void
// Does: opens input file by name, reads in adjancency list
//       of course dependencies.
void read_majors_from_file(char *fname, LinkedList<string> courses[])
{
    ifstream infile;
    infile.open(fname);
    if (!infile.is_open())
    {
        cerr << "Could not open input file for reading\n";
        exit(1);
    }
    int course_counter = 0;
    while (!infile.eof())
    {
        string line;
        getline(infile, line);

        if (line == "-1")
            break;
        else if (course_counter < NUM_CORE)
        {
            stringstream ss(line);
            while (!ss.eof())
            {
                string tmp;
                ss >> tmp;
                if (tmp == "-1")
                    break;
                courses[course_counter].insert(tmp);
            }
            course_counter++;
        }
    }
    infile.close();
}

// Function check_legitimacy
// Input: file name, array of Linked Lists
// Returns: void
// Does: opens input file by name, checks permutations against adjacency list
void check_legitimacy(char *fname)
{
    LinkedList<string> permutation[NUM_PERM];
    ifstream infile;
    infile.open(fname);
    if (!infile.is_open())
    {
        cerr << "Could not open input file for reading\n";
        exit(1);
    }
    //read into permutation linked list
    int perm_counter = 0;
    while (!infile.eof())
    {
        string line;
        getline(infile, line);

        if (line == "-1")
            break;
        else if (perm_counter < NUM_PERM)
        {
            stringstream ss(line);
            while (!ss.eof())
            {
                string tmp;
                ss >> tmp;
                if (tmp == "-1")
                    break;
                permutation[perm_counter].insert(tmp);
            }
            perm_counter++;
        }
    }
    infile.close();
    int legit = 0;
    //check legitimacy
    for (int i = 0 ; i < perm_counter; i++)
    {
        //case 1: first value is comp11
        if (permutation[i].get_value_at(1) == "COMP11")
        {
            //case 2: second value is comp15
            if (permutation[i].get_value_at(2) == "COMP15")
            {
                legit++;
                //print the permutation
                print_perm(permutation[i]);
            }
            //case 3: second value is comp61 and the following values are its
            //permissible courses
            if (permutation[i].get_value_at(2) == "COMP61")
            {
                if ((permutation[i].get_value_at(3) == "COMP105") ||
                     (permutation[i].get_value_at(3) == "COMP160") ||
                     (permutation[i].get_value_at(3) == "COMP170"))
                {
                    legit++;
                    //print the permutation
                    print_perm(permutation[i]);
                }
            }
        }
    }
    cout << "There are " << legit << " valid permutations." << endl;
}

// Function print_perm
// Input: LinkedList<String>
// Returns: void
// Does: prints a linked list
void print_perm(LinkedList<string> perm)
{
    cout << perm.get_value_at(0);
    for (int i = 1; i < 8; i++)
    {
        cout << perm.get_value_at(i) << " ";
    }
    cout << endl;
}
