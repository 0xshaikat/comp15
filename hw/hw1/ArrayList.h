/*
 * Shaikat Islam
 * 01-02-2018
 * ArrayList.h
 * COMP15
 * Spring 2018 
 *
 * Interface for Array of Pirates, matey
 */

#include "Pirate.h"

#ifndef ARRAY_H_
#define ARRAY_H_

const int MAX_PIRATES = 100;

class ArrayList
{
public:
    // Default constructor
    ArrayList();
    //destructor
    ~ArrayList();
    // The basic operations:
    // Insert, Delete, and Find
    Pirate find_pirate(Pirate, bool &) const;
    void insert_pirate(Pirate);
    void delete_pirate(Pirate);
    Pirate get_next_pirate();

    // Start over at the beginning of the list
    void make_empty();
    void reset_array();

    //expand array
    void expand();

    //shrink array
    void shrink();
    
    // Return some basic info
    int get_length() const;

    // Print the array
    void print(ostream &) const;

private:
    int length;
    Pirate *pirates;
    int curr_pos;
    //tmp_c for MAX_CAPACITY
    int tmp_c;
};

#endif
