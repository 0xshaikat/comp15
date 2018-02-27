#include <iostream>
#include <string>
using namespace std;
#ifndef SURVIVOR_H_
#define SURVIVOR_H_

class Survivor
{
 public:
    Survivor();
    Survivor(string, string, string, string, float);
    void print(ostream &);
    void generate_next_survivor(ifstream &);
    void generate_n_survivor(ifstream &, int);
    void set_name(string, string);
    friend bool operator == (const Survivor &, const Survivor &);
    friend bool operator < (const Survivor &, const Survivor &);
    friend bool operator > (const Survivor &, const Survivor &);
    float get_age();
    int get_s_id();

 private:
    string first;
    string last;
    string hometown;
    string state;
    float age;
    int s_id;
};//end class

#endif
