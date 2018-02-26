//Shaikat Islam
//COMP15
//Homework 3
//15-02-2018

#ifndef STACK_H_
#define STACK_H_
#include <exception>
#include <string>
using namespace std;

//define Node for linked list base
struct Node
{
  double value;
  Node *next;
};
//exception definitions
class FullStack : public exception{
 public:
  const char * what() const throw() {return "Aw shucks, the stack is full!\n";};
};

class EmptyStack : public exception{
 public:
  const char * what() const throw() {return "Aw shucks, the stack is empty!\n";}
};
//class definitions
class Stack
{
 public:
  Stack(); // constructor
  ~Stack(); // destructor
  Stack(const Stack &); // copy constructor
  Stack & operator = (const Stack &); // assignment operator
  //necessary functions, as per spec
  bool is_empty() const;
  bool is_full() const;
  void make_empty();
  int get_size() const;
  double top() const;
  void push(double);
  void pop();
  int size;
 private:
  Node *head;
  Node *curr_pos;
};

#endif
