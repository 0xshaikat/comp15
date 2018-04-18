// Shaikat Islam
// COMP15
// Phase II
// 18-04-2018

#include <iostream>
#include <string>
#include "LinkedHashNode.h"
#include "HashMap.h"
using namespace std;

//int main
//Purpose: run test on HashMap
//Returns: int
//Parameters: none
int main()
{
    //allocation test
    HashMap h;
    cout << "Constructor success!\n" ;
    string a = "a";
    string a1 = "a";
    string c = "c";
    string e = "e";
    string g = "g";
    //insert test
    h.insert(a , "b");
    h.insert(a, "b1");
    h.insert( c , "d");
    h.insert( e , "f");
    h.insert( g , "h");
    //get test
    string r1 = h.get(a);
    string r2 = h.get(c);
    string r3 = h.get(e);
    string r4 = h.get(g);
    cout << r1 << endl;
    //remove test
    h.remove(a);
    h.remove(c);
    h.remove(e);
    h.remove(g);
    if(h.get_size() == 0)
    {
        cout << "Delete success!\n";
    }// end if
    else
    {
        cout << "Delete failed!";
    }// end else

}// end main
