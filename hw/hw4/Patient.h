/* COMP15
 * Shaikat Islam
 * HW4
 * 14-03-2018
 * Patient.h
 *
 * COMP15
 * Spring 2018
 *
 * Interface for a Patient
 *
 */

#include <string>
using namespace std;

#ifndef PATIENT_H_
#define PATIENT_H_

enum Priority {ONE, TWO, THREE, FOUR, FIVE};

class Patient
{
public:
    //constructor
    Patient();
    //parameterized constructor
    Patient(string, string);
    //calculates priority of patient
    void calculate_priority(bool, bool, double, unsigned, int, bool);

    //overloaded operators
    friend bool operator < (const Patient &, const Patient &);
    friend bool operator > (const Patient &, const Patient &);
    friend bool operator == (const Patient &, const Patient &);
    friend ostream & operator << (ostream &, const Patient &);

    //helper
    int get_time() const;
    bool find_early(Patient, Patient) const;

private:
    string fname, lname;
    bool head_wound;
    bool chest_pain;
    double temp;
    unsigned pulse;
    int time_in;
    Priority priority;
};

#endif
