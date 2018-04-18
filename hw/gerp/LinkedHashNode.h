// Shaikat Islam
// COMP15
// Phase II
// 18-04-2018

#include <iostream>
#include <string>
using namespace std;

#ifndef LINKEDHASHNODE_H_
#define LINKEDHASHNODE_H_

class LinkedHashNode
{
 private:
    string key;
    string value;
    LinkedHashNode *next;
 public:
    //parameterized constructor
    LinkedHashNode(string, string);

    //private member functions
    string get_key();
    string get_value();
    void set_value(string);
    LinkedHashNode* get_next();
    void set_next(LinkedHashNode *);
};

#endif
