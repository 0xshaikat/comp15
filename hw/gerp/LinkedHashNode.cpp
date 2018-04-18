// Shaikat Islam
// COMP15
// Phase II
// 18-04-2018

#include <iostream>
#include <string>
#include "LinkedHashNode.h"
using namespace std;

LinkedHashNode::LinkedHashNode(string key, string value)
{
    this->key = key;
    this->value = value;
    this->next = NULL;
}// end parameterized constructor

string LinkedHashNode::get_key()
{
    return key;
}// end get_key

string LinkedHashNode::get_value()
{
    return value;
}// end get_value

void LinkedHashNode::set_value(string to_set)
{
    this->value = to_set;
}// end set_value

LinkedHashNode* LinkedHashNode::get_next()
{
    return next;
}// end get_next

void LinkedHashNode::set_next(LinkedHashNode *n)
{
    this->next = n;
}// end set_next
