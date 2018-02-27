#include "Survivor.h"
#include <iostream>

#ifndef TREE_H_
#define TREE_H_

typedef Survivor TreeItem;

struct BinaryNode
{
    //typedef Survivor TreeItem; // gotta define Survivor class first to work!
  TreeItem info;
  BinaryNode *left;
  BinaryNode *right;
};



#endif
