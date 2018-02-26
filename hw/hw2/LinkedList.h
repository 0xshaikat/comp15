/*
 * LinkedList.h
 * COMP15
 * Spring 2018
 *
 * Interface for Linked List of Planets
 *
 * What is an astronaut's favorite candy bar?
 *
 * A milky way!
 */

#include "Planet.h"
#include <fstream>

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

class LinkedList
{
public:
    // Default constructor
    LinkedList();

    //destructor
    ~LinkedList();

    // Copy Constructor
    LinkedList(const LinkedList &);
    
    // Assignment Operator
    LinkedList & operator = (const LinkedList &);

    // The basic operations:
    // Insert, delete, and find
    void insert_planet(Planet);
    Planet get_next_planet();
    void delete_planet(Planet);
    Planet find_planet(Planet, bool &);

    //make_empty and reset_list
    void make_empty();
    void reset_list();

    // Return some basic info
    int get_length() const;

    // Print the list
    void print(ostream &) const;
    // check if list is full or not
    bool is_full() const;

private:
    int length;
    NodeType *head;
    NodeType *curr_pos;
};

#endif
