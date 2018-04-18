// Shaikat Islam
// COMP15
// Phase II
// 18-04-2018

#include <iostream>
#include <string>
#include "LinkedHashNode.h"
using namespace std;

#ifndef HASHMAP_H_
#define HASHMAP_H_

class HashMap
{
 private:
    float threshold;
    int max;
    int table_size;
    int size;
    LinkedHashNode **table;
    void resize();
 public:
    //constructor
    HashMap();
    //destructor
    ~HashMap();
    void set_threshold(float);
    string get(string);
    void insert(string, string);
    void remove(string);
    int get_size();

};

#endif
