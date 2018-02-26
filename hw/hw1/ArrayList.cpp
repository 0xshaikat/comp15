/*
 * Shaikat Islam
 * 01-02-2018
 * Array.cpp
 * COMP15
 * Spring 2018
 *
 * Implementation for Arrrrrrray of Pirates
 */
#include <iostream>
#include "ArrayList.h"
using namespace std;

//ArrayList::ArrayList()
//Purpose: constructor
//Parameters: none
//Returns: nothing
// Default constructor
// Length and current position default to 0
ArrayList::ArrayList()
{
  pirates = new Pirate[MAX_PIRATES];
  length = 0;
  curr_pos = 0;
  tmp_c = MAX_PIRATES;
}//end constructor

//ArrayList::~ArrayList()
//Purpose: destructor
//Parameters: none
//Returns: nothing
ArrayList::~ArrayList()
{
  delete []pirates;
}//end destructor

// Function find_pirate
// Inputs: Pirate object, bool by reference
// Returns: Pirate object
// Does: Looks for pirate in the array, modifies bool if found
//       Returns the object from the list and not the passed one
//       (In case they're different.)
Pirate ArrayList::find_pirate(Pirate p, bool &found) const
{
    int location = 0;

    while ((location < length) && !found)
    {
        if (p == pirates[location])
        {
            found = true;
            p = pirates[location];
            break;
        }
        location++;
    }
    return p;
}//end find_pirate

// Function insert_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Adds Pirate to end of array, increases length
void ArrayList::insert_pirate(Pirate p)
{
  //call expand() in beginning of function
  expand();
  //if found add pirate and increment length
  bool found;
  Pirate tmp = find_pirate(p, found);
  if (!found)
    {
      pirates[length] = p;
      length++;
    }//end if
}//end ArrayList::insert_pirate

// Function delete_pirate
// Inputs: Pirate object
// Returns: Nothing
// Does: Deletes pirate, shifts everything else over
void ArrayList::delete_pirate(Pirate p)
{
  //modify found bool and create position var
  bool found;
  Pirate fnd = find_pirate(p, found);
  int position;
  if (found)
    {
      //find position of the pirate in the array
      for (int i = 0; i < length; i++)
        {
          //if pirate matches found one
          //change the position
          if (pirates[i] == fnd)
            {
              position = i;
            }//end if
        }//end for

      //shift cells
      for(int j = position + 1; j < length; j++)
        {
          Pirate tmp = pirates[j];
          pirates[j-1] = tmp;
        }//end for
      length--;
      //call shrink at end of function
      shrink();
    }//end if
}//end delete

// Function get_next_pirate
// Input: None
// Returns: Pirate object
// Does: Returns pirate at curr_pos
// Increments curr_pos, but wraps around
Pirate ArrayList::get_next_pirate()
{
    Pirate p = pirates[curr_pos];
    curr_pos = (curr_pos + 1) % length;
    return p;
}//end get_next_pirate

// Function make_empty
// Input: none
// Returns: none
// Does: sets length to 0 (memory not modified)
void ArrayList::make_empty()
{
    length = 0;
}//end make_empty()

// Function reset_array
// Input: none
// Returns: none
// Does: sets curr_pos to 0 
void ArrayList::reset_array()
{
    curr_pos = 0;
}//end reset_array

//ArrayList::expand()
//Purpose: expand array if length >= tmp_c
//Parameters: none
//Returns: nothing
void ArrayList::expand()
{
  //if length is greater than capacity
  if (length >= tmp_c)
    {
      //declare new pointer
      Pirate *s;
      //set the new array
      s =  new Pirate[tmp_c *= 2];
      //cout to output.txt
      cout << "Expand to 200" << endl;
      //copy contents of array
      for (int i = 0; i < length; i++)
        {
          s[i] = pirates[i];
        }//end for
      
      //delete pirates array and point pirates array 
      delete []pirates;
      //set pointer
      pirates = s;
    }//end if
}//end expand

//ArrayList::shrink()
//Purpose: shrink array if length is less than twice tmp_c
//Parameters: none
//Returns: nothing
void ArrayList::shrink()
{
  //if length is less than tmp_c/2
  if (length < (tmp_c/2))
    {
      //print to ostream
      cout << "Contract to 50" << endl;
      //declare new pointer
      Pirate *s;
      //allocate lower amount of memory
      s = new Pirate[tmp_c/=2];
      //copy contents of array
      for (int i = 0; i < length; i++)
        {
          s[i] = pirates[i];
        }//end for
      
      //delete pirates array and point pirates array to s
      delete []pirates;
      pirates = s;
    }//end if
}//end shrink

// Function print
// Input: none, const
// Returns: none
// Does: Prints array from 0 to length
void ArrayList::print(ostream &ous) const 
{
  //traverse through ArrayLIST
  for (int i = 0; i < length; i++)
    {
      //if it's not the first element
      if (i != length - 1)
        {
          //print to ostream
          pirates[i].print(ous);
          ous << ", ";
        }//end if
      else
        {
          pirates[i].print(ous);
        }
    }//end for
}//end print

// Function get_length
// Input: none, oncst
// Returns: int
// Does: Returns the value in length attribute
int ArrayList::get_length() const
{
    return length;
}//end get_length()
