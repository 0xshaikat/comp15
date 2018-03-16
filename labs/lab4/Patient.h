/*
 * Patient.h
 *
 * COMP15
 * Spring 2018
 *
 * Starter code for Lab 4
 */

#include <string>
using namespace std;

#ifndef PATIENT_H_
#define PATIENT_H_

//enum declaration
enum Priority{ ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5};

class Patient
{
public:
    Patient();
    Patient(string, string);
    void calculate_priority(bool, bool, double, unsigned);

    friend bool operator < (const Patient &, const Patient &);
    friend bool operator > (const Patient &, const Patient &);
    friend ostream & operator << (ostream &, const Patient &);

private:
    string fname;
    string lname;
    bool chest_pain;
    bool head_wound;
    double temp;
    unsigned pulse;
    Priority priority;
};

#endif
