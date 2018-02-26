#ifndef RPNCALC_H_
#define RPNCALC_H_
#include <string>
#include <iostream>
#include "Stack.h"
using namespace std;

class RPNCalc
{
 public:
  RPNCalc();
  void run();
  void rstream(istream &);
  bool is_dub(string);
  bool is_operator(string);
  void calculate(string);
 private:
  Stack s;
};

#endif
