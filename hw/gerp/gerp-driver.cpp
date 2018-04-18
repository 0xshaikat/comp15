// Shaikat Islam
// COMP15
// Phase II
// 18-04-2018

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <exception>
#include "HashMap.h"
#include "DirNode.h"
#include "FSTree.h"
#include <string>
#include <locale>
using namespace std;

// function definitions
bool check_dir(string);
string get_path(string);
bool perm(string);
void query(string, string, bool);
vector<string> fill_vector(string);
void preorder_fill(DirNode *, string, vector<string> *);
string string_manipulator(string, bool &);
string lowercase(string);
string process_string(string);
bool invalid_character(char);

//int main
//Purpose: run program
//Returns: int
//Parameters:
int main(int argc, char *argv[])
{
    //print error
    if (argc != 2)
    {
        cout << "usage: ./gerp directory\n";
        return 0;
    }// end if
    //subdirectory not found
    else if(check_dir(argv[1]))
    {
        cout << "Could not build index, exiting.\n";
        return 0;
    }// end else if
    //no permissions
    string p = get_path(argv[1]);
    string q;
    bool sensitive;
    if(perm(p))
    {
        cout << "Could not build index, exiting.\n";
    }// end else if
    //check for query
    else
    {
        cout << "Query?\n";
        while (cin >> q)
        {
            q = string_manipulator(q, sensitive);
            if (q == "q" || q == "quit")
            {
                cout << "Goodbye! Thank you and have a nice day!\n";
                return 0;
            }// end if
            query(argv[1], q, sensitive);
            cout << "Query?\n";
        }//end while
    }// end else
    cout << "Goodbye! Thank you and have a nice day!\n";
}// end main

void query(string dir, string search, bool b)
{
    //fill vector for files to check for search term
    vector<string> files = fill_vector(dir);
    HashMap h;
    //case sensitive search
    if (b)
    {
        //search for query within files
        for(size_t i = 0; i < files.size(); i++)
        {
            ifstream fs;
            string line = "";
            int line_no = 0;
            fs.open(files.at(i));
            while(getline(fs, line))
            {
                istringstream ss(line);
                string s;
                while (ss >> s)
                {
                    if (s == search)
                    {
                        string linenum= to_string(line_no);
                        string path = files.at(i) + ":" + linenum + ":" + " " + line;
                        h.insert(search, path);
                        line_no++;
                        cout << path << endl;
                    }// end if
                }// end while
                line_no++;
            }// end while
            fs.close();
        }// end for
    }//end if
   //case insensitive search
    else
    {
        //search for query within files
        for(size_t i = 0; i < files.size(); i++)
        {
            ifstream fs;
            string line = "";
            int line_no = 0;
            fs.open(files.at(i));
            while(getline(fs, line))
            {
                istringstream ss(line);
                string s;
                while (ss >> s)
                {
                    if (lowercase(s) == search)
                    {
                        string linenum= to_string(line_no);
                        string path = files.at(i) + ":" + linenum + ":" + " " + line;
                        h.insert(search, path);
                        line_no++;
                        cout << path << endl;
                    }// end if
                }// end while
                line_no++;
            }// end while
            fs.close();
        }// end for
    }// end else
    //query failed?
    if (h.get_size() == 0)
    {
        cout << search << " Not Found. Try with @insensitive or @i.\n";
    }
}// end query

//==STRING PROCESSING===========================================================
string string_manipulator(string s, bool &b)
{
    size_t found_a = s.find("@i");
    size_t found_a1 = s.find("@insensitive");
    string result;
    if (found_a1 == 0)
    {
        for (size_t i = 12; i < s.length(); i++)
        {
            result += s[i];
            b = false;
        }
        result = lowercase(process_string(result));
    }// end else if
    else if (found_a == 0)
    {
        for (size_t x = 2; x < s.length(); x++)
        {
            result += s[x];
        }
        result = lowercase(process_string(result));
        b = false;
    }// end else if
    else
    {
        result = process_string(s);
        b = true;
    }// end else
    return result;
}// end string_manipulator

string lowercase(string s)
{
    locale loc;
    string result;
    for(size_t i = 0; i < s.length(); i++)
    {
        result += tolower(s[i], loc);
    }// end for
    return result;
}// end lowercase

//process_string
//Purpose: remove leading and trailing non-alphanum chars from a string
//Returns: string
//Parameters: string
string process_string(string s)
{
    //size of string
    size_t len = s.length();

    //remove the invalid chars at front
    while(!invalid_character(s[0]))
    {
        if (len <= 0)
        {
            return "";
        }// end if
        s.erase(0,1);
        len--;
    }//end while

    //remove the invalid chars at the bacl
    while(!invalid_character(s[len]))
    {
        if (len <= 0)
        {
            return "" ;
        }// end if
        s.erase(len, 1);
        len--;
    }// end while

    //return processed string
    return s;
}// end process_string

//invalid_character
//Purpose: return false if invalid alphanum, true otherwise
//Returns: bool
//Parameters: char
bool invalid_character(char c)
{
    if (c > 64 && c < 91)
    {
        return true;
    }// end if
    if (c > 96 && c < 123)
    {
        return true;
    }// end if
    if (c > 47 && c < 58)
    {
        return true;
    }// end if
    return false;
}// end invalid_character

//==FILE PROCESSING=============================================================
//bool check_dir
//Purpose: Check if a directory exists.
//Returns: bool
//Parameters: string
bool check_dir(string dir)
{
    FSTree fs = FSTree(dir);
    if(fs.get_root()->is_empty())
    {
        return true;
    }// end if
    return false;
}//end check_dir

//string get_path
//Purpose: Return path of user inputted directory.
//Returns: string
//Parameters: string
string get_path(string dir)
{
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    string path(cwd);
    string final_path = path + dir;
    return final_path;
}// end get_path

//bool perm
//Purpose: Check for permissions of a directory/file.
//Returns: bool
//Parameters: string
bool perm(string path)
{
    const char *check_p = path.c_str();
    bool read_p = false;
    bool write_p = false;
    bool exec_p = false;

    //check permissions
    if (access(check_p, R_OK) == 0)
    {
        read_p = true;
    }
    if (access(check_p, W_OK) == 0)
    {
        write_p = true;
    }
    if (access(check_p, X_OK) == 0)
    {
        exec_p = true;
    }
    // if read and write permissions accepted, then the directory is valid
    if (read_p && exec_p)
    {
        return true;
    }// end if
    return false;
}// end perm

vector<string> fill_vector(string dir)
{
    vector<string> v;
    FSTree fs = FSTree(dir);
    preorder_fill(fs.get_root(), dir, &v);
    return v;
}// end fill_vector

void preorder_fill(DirNode *dir, string s, vector <string> *vec)
{
    int num_files = dir->num_files();
    //print final path for file in a DirNode (should be run after last recursive
    //run)
    string path_name;
    if (num_files > 0)
    {
        //print final paths for a DirNode
        for (int i = 0; i < num_files; i++)
        {
            path_name = s + "/" + dir->get_file(i);
            vec->push_back(path_name);
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
            preorder_fill(sub, s_1, vec);
        }// end for
    }// end if
}// end preorder_fill
