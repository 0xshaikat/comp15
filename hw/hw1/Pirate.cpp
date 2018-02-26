/*
 * Shaikat Islam
 * 01-02-2018
 * Pirate.cpp
 * COMP15
 * Spring 2018
 *
 * Implarrrrrrmentation of a Pirate
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Pirate.h"
using namespace std;

int Pirate::pirate_count = 0;

//Pirate::Pirate()
//Purpose: Constructor.
//Parameters: none
//Returns: nothing
Pirate::Pirate()
{
    pirate_id = -1;
    name = "Cap'n Hook";
}//end Pirate()

//Pirate::Pirate(string n)
//Purpose: Parameterized constructor.
//Parameters: string n
//Returns: nothing
Pirate::Pirate(string n)
{
    assign_pirate_id();
    name = n;
}//end pirate()

//Pirate::print
//Purpose: print to ostream/output
//Parameters: ostream &os
//Returns: nothing
void Pirate::print(ostream &os) const
{
  //print to outstream
      os << pirate_id << " " << name;
}//end print

//Pirate::generate_pirate_name
//Purpose: generate random pirate name
//Parameters: ifstream &infile, int range
//Returns: nothing
void Pirate::generate_pirate_name(ifstream &infile, int range)
{
    string pname;
    int rando = rand() % range;
    int count = 0;

    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, pname))
    {
        if (count == rando)
        {
            name = pname;
            break;
        }
        count++;
    }
}//end generate_pirate_name

//Pirate::generate_next_pirate
//Purpose: generate the next pirate from the infile
//Parameters: ifstream &infile
//Returns: nothing
void Pirate::generate_next_pirate(ifstream &infile)
{
  //store string from getline
  string pname;
  int count = 0;
  
  infile.clear();
  infile.seekg(0, ios::beg);
  //traverse the file
  while (getline(infile, pname))
    {
      //match count with pirate_count
      if (count == pirate_count)
        {
          name = pname;
          break;
        }//end if
      //increment count 
      count++;
    }//end while
}//end Pirate::generate_next_pirate

//Pirate::assign_pirate_id
//Purpose: assigns the pirate id to pirate
//Parameters: none
//Returns: nothing
void Pirate::assign_pirate_id()
{
    pirate_id = pirate_count++;
}//end assign_pirate_id

//bool operator
//Purpose: checks for equality
//Parameters: Pirate p1, Pirate p2
//Returns: bool
bool operator == (const Pirate &p1, const Pirate &p2)
{
    return (p1.pirate_id == p2.pirate_id);
}//end bool operator

