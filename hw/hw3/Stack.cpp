//Shaikat Islam
//COMP15
//Homework 3
//2018-02-15
#include "Stack.h"
#include <iostream>
using namespace std;

//constructor
Stack::Stack()
{
  size  = 0;
  head = NULL;
  curr_pos = NULL;
}//end constructor

//destructor 
Stack::~Stack()
{
  Node *curr = NULL;
  while (head != NULL)
    {
      curr = head->next;
      delete head;
      head = curr;
    }//end while
}//end destructor

//copy constructor
Stack::Stack(const Stack &s)
{
  //copy attributes
  size = s.size;
  curr_pos = NULL;
  //check if head is NULL
  if (s.head == NULL)
    {
      head = NULL;
    }
  else
    {
      head = new Node;
      head->value = s.head->value;
      head->next = NULL;
      Node *curr = head;
      Node *orig = s.head;
      //traverse array/deep copy
      while (orig->next != NULL)
        {
          curr->next = new Node;
          curr->next->value = orig->next->value;
          curr->next->next = NULL;
          orig = orig->next;
          curr = curr->next;
        }//end while
    }//end if
}//end copy constructor

//assignment operator
Stack & Stack::operator = (const Stack &s)
{
  Node *temp;
  while (head != NULL)
    {
      temp = head; 
      head = head->next;
      delete temp;
    }
  size = s.size;
  curr_pos = NULL;
  if (s.head == NULL)
    head = NULL;
  else
    {
      head = new Node;
      head->value = s.head->value;
      head->next = NULL;
      Node *curr = head;
      Node *orig = s.head;
      while (orig->next != NULL)
        {
          curr->next = new Node;
          curr->next->value = orig->next->value;
          curr->next->next = NULL;
          orig = orig->next;
          curr = curr->next;
        }
    }
  return *this;
}//end assignment operator

//is_empty()
//Purpose: check if stack is empty
//Returns: bool
//Parameters: none
bool Stack::is_empty() const
{
  return (size == 0);
}//end is_empty()

//is_full()
//Purpsoe: check if stack is full
//Returns: bool
//Parameters: none
bool Stack::is_full() const
{
  //allocate new node, if it fails, then stack is full
  try
    {
      Node *n = new Node;
      delete n;
      return false;
    }//end try
  catch (bad_alloc exception)
    {
      return true;
    }//end catch
}//end is_full()

//make_empty()
//Purpose: clear the stack of dynamic memory
//Returns: void
//Parameters: none
void Stack::make_empty()
{
  //very similar to destructor
  Node *curr = NULL;
  while (head != NULL)
    {
      curr = head->next;
      delete head;
      head = curr;
    }//end while
  size = 0;
}//end make_empty()

//get_size()
//Purpose: return size of stack
//Returns: int
//Parameters: none
int Stack::get_size() const
{
  return size;
}//end get_size()

//top()
//Purpose: return the uppermost value of a stack
//Returns: double
//Parameters: none
double Stack::top() const
{
  return head->value;
}//end top()

//push(double d)
//Purpose: push a double value to stack
//Returns: void
//Parameters: (double d)
void Stack::push(double d)
{
  //get a node with value of the double
  if (is_full())
    {
      throw FullStack();
    }//end if
  //dynamically allocate new head, move old head
  else
    {
      Node *n =  new Node;
      if (head == NULL)
        {
          n->value = d;
          n->next = NULL;
          head = n;
          size++;
        }//end if
      else
        {
          n->value = d;
          n->next = head;
          head = n;
          size++;
        }//end else
    }//end else
}//end push(double d)

//void pop()
//Purpose: remove uppermost element from stack
//Returns: void
//Parameters: noen
void Stack::pop()
{
  //check if it's empty first
  if (is_empty())
    {
      throw EmptyStack();
    }
  //delete old node, allocate new one to head
  else
    {
      Node *o = head;
      head = head->next;
      size--;
      delete o;
    }//end else
}//end pop()
