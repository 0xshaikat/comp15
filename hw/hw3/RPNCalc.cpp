//Shaikat Islam
//COMP15
//Homework 3
//15-02-2018
#include "Stack.h"
#include "RPNCalc.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <fstream>
using namespace std;

//constructor inititalizes new stack
RPNCalc::RPNCalc()
{
  Stack s;
}//end constructor

//run()
//Purpose: run rstream(cin)
//Returns: void
//Parameters: none
void RPNCalc::run()
{
  //run helper function rstream
  rstream(cin);
}//end run

//rstream(istream &)
//Purpose: implement RPNCalc on various instreams
//Returns: void
//Parameters: (istream &)
void RPNCalc::rstream(istream &mstream)
{
  //while the function does not encounter CTRL-F (eof)
  while(!mstream.eof())
    {
      //declare variables to be used later in loop
      double d;
      string st;
      //instream to st
      mstream >> st;
      //overlying try catch block to catch empty stacks
      try
        {
          //initial case to print
          if (st == "p" || st == "P")
            {
              //check if stack is empty first
              if (s.is_empty())
                {
                  throw EmptyStack();
                }//end if
              //print value at top of stack
              else
                {
                  cout << s.top() << endl;
                }//end else
            }//end if
          //file IO
          else if (st == "f" || st == "F")
            {
              //read in to ifstream, mstream in to fname
              string fname;
              ifstream in;
              mstream >> fname;
              //file opening and error handling
              in.open(fname);
              if(!in.is_open())
                {
                  cerr << "Cannot read file, or file does not exist.\n";
                }//end if
              //run rstream on file input
              else
                {
                  rstream(in);
                  in.close();
                }//end else
             }//end else if
          //quit function
          else if (st == "q" || st == "Q")
            {
              return;
            }//end else if
          //make the stack empty
          else if (st == "c" || st == "C")
            {
              s.make_empty();
            }//end else if
          //check if it is a double and push it to top of stack
          else if (is_dub(st))
            {
              //use stod to convert string to dub
              d = stod(st);
              if (s.is_full())
                {
                  throw FullStack();
                }//end if
              else
                {
                  s.push(d);
                }//end else
            }//end else if
          //check if input is an operator
          else if (is_operator(st))
            {
              //helper function
              calculate(st);
            }//end else if
          else
            {
              //everything else
              cout << "Not a valid input/EOF!\n";
            }//end else
        }//end try
      catch(...)
        {
          cout << "Can't do that with an empty stack!" << endl;
        }//end catch
    }//end while
}//end runstream

//is_dub(string)
//Purpose: check if a string is a double using stod
//Returns: bool
//Parameters: (string)
bool RPNCalc::is_dub(string input)
{
  double op;
  bool is_d;
  //try and catch to check if string is a double using stod
  try
    {
      op = stod(input);
      is_d = true;
    }//end try
  catch(invalid_argument exception)
    {
      is_d = false;
    }//end catch
  return is_d;
}//end is_dub

//is_operator(string)
//Purpose: checks if a string is an operator
//Returns: bool
//Parameters: (string)
bool RPNCalc::is_operator(string input)
{
  //check if a string is an operator
  bool is_o = input == "*" || input == "+" || input == "-" || input == "/";
  if (is_o)
    {
      return true;
    }
  return false;
}//end is_operator

//calculate(string)
//Purpose: perform calculations on stack
//Returns: void
//Parameters: (string)
void RPNCalc::calculate(string input)
{
  double a;
  double b;
  double result;
  //check if stack is empty or only one element
  if (s.is_empty() || s.size == 1)
    {
      throw EmptyStack();
    }
  else
    {
      //pop first two values and save them as variables
      a = s.top();
      s.pop();
      b = s.top();
      s.pop();

      //process doubles based on operator
      if(input == "+")
        {
          result = a+b;
        }//end if
      else if(input == "-")
        {
          result = a-b;
        }//end else if
      else if(input == "*")
        {
          result = a*b;
        }//end else if
      else
        {
          result = a/b;
        }//end else
      //if stack is full, throw an exception
      if (s.is_full())
        {
          throw FullStack();
        }
      else
        {
          s.push(result);
        }//end else
    }//end else
}//end calculate
