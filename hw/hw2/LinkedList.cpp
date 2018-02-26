/*
 * LinkedList.cpp
 * COMP15
 * Spring 2018
 * 
 * Implementation for Linked List of Planets
 *
 * What is an astronaut's favorite candy bar?
 *
 * A mars bar!
 */

#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor
LinkedList::LinkedList()
{
    length = 0;
    head = NULL;
    curr_pos = NULL;
}

//destructor
LinkedList::~LinkedList()
{
  NodeType *curr = NULL;
  while (head != NULL)
    {
      curr = head->next;
      delete head;
      head = curr;
    }//end while
}//end destructor

// Copy Constructor
LinkedList::LinkedList(const LinkedList &l)
{
  //copy attributes
  length = l.length;
  curr_pos = NULL;
  //check if head is NULL
  if (l.head == NULL)
    {
      head = NULL;
    }
  else
    {
      head = new NodeType;
      head->info = l.head->info;
      head->next = NULL;
      NodeType *curr = head;
      NodeType *orig = l.head;
      //traverse array/deep copy
      while (orig->next != NULL)
        {
          curr->next = new NodeType;
          curr->next->info = orig->next->info;
          curr->next->next = NULL;
          orig = orig->next;
          curr = curr->next;
        }//end while
    }//end if
}//end copy const

// Assignment operator
LinkedList & LinkedList::operator = (const LinkedList &l)
{
    NodeType *temp;
    while (head != NULL)
    {
        temp = head; 
        head = head->next;
        delete temp;
    }
    length = l.length;
    curr_pos = NULL;
    if (l.head == NULL)
        head = NULL;
    else
    {
        head = new NodeType;
        head->info = l.head->info;
        head->next = NULL;
        NodeType *curr = head;
        NodeType *orig = l.head;
        while (orig->next != NULL)
        {
            curr->next = new NodeType;
            curr->next->info = orig->next->info;
            curr->next->next = NULL;
            orig = orig->next;
            curr = curr->next;
        }
    }
    return *this;
}

// Function insert_planet
// Input: Planet object
// Returns: None
// Does: Adds Planet to beginning of array, increases length
void LinkedList::insert_planet(Planet p)
{
    NodeType *location = new NodeType;
    location->info = p;
    location->next = head;

    head = location;
    length++;
}

// Function get_next_planet
// Inputs: none
// Returns: none
// Does: Returns the Planet object at the current pos
//       Wraps around to beginning if we're at the end
//       Returns a default planet if empty
Planet LinkedList::get_next_planet()
{
    if (length == 0)
    {
        Planet p;
        return p;
    }
    if (curr_pos == NULL)
        curr_pos = head;
    else
        curr_pos = curr_pos->next;
    return curr_pos->info;
}

// Function find_planet
// Inputs: Planet object, boolean reference
// Returns: Planet object
Planet LinkedList::find_planet(Planet p, bool &b)
{
  NodeType *tmp = head;
  //so long as the LL is not empty/null, traverse
  while (tmp != NULL)
    {
      if (tmp->info == p)
        {
          b = true;
          return p;
        }//end if
      else
        {
          tmp = tmp->next;
        }//end else
    }//end while
  b = false;
  return p;
}//end find_planet

// Function delete_planet
// Inputs: Planet object
// Returns: void
void LinkedList::delete_planet(Planet p)
{
  bool found;

  Planet p_delete;
  p_delete = find_planet(p, found);
  if (found)
    {
      NodeType *prev;
      NodeType *curr;
      curr = head;
      //traverse array and get position of found planet
      while(curr->info != p_delete)
        {
          prev = curr;
          curr = curr->next;
        }
      //three cases
      //@head
      if (curr->info == head->info)
        {
          NodeType *tmp;
          tmp = head;
          head = head->next;
          delete tmp;
        }//end if
      //@any position
      else if (curr->next != NULL)
        {
          prev->next = curr->next;
        }//end else if
      //@tail
      else
        {
          prev->next = NULL;
          delete curr;
        }//end else
      length--;
    }//end if
}//end delete_planet

// Function make_empty
// Inputs: none
// Returns: void
void LinkedList::make_empty()
{
  //similar to destructor
  NodeType *curr = NULL;
  while (head != NULL)
    {
      curr = head->next;
      delete head;
      head = curr;
    }//end while
}//end make_empty

// Function reset_list
// Inputs: none
// Returns: void
void LinkedList::reset_list()
{
  curr_pos = head;
}//end reset_list

// Function get_length, const
// Inputs: none
// Returns: int, length of list
int LinkedList::get_length() const
{
    return length;
}

// Function print, const
// Inputs: ostream object
// Returns: none
// Does: prints every element in the list
void LinkedList::print(ostream &out) const
{
    NodeType *location = head;
    while (location != NULL)
    {
        (location->info).print(out);
        out << endl;
        location = location->next;
    }
}

// Function is_full(), const
// Inputs: none
// Returns: bool
// Does: returns true if LL is full/false otherwise
bool LinkedList::is_full() const
{
  try
    {
      NodeType *node = new NodeType;
      delete node;
      return false;
    }//end try block
  catch(bad_alloc exception)
    {
      return true;
    }//end catch block
}//end is_full
