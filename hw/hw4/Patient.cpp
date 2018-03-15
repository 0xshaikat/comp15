/* COMP15
 * Shaikat Islam
 * HW4
 * 14-03-2018
 * Patient.cpp
 *
 * Implementation for Patient class
 *
 * COMP15
 * Spring 2018
 * Lab 4
 */

#include <iostream>
#include "Patient.h"
using namespace std;

// Default constructor
Patient::Patient()
{
    fname = "Jane";
    lname = "Doe";
    chest_pain = false;
    head_wound = false;
    temp = 98.6;
    pulse = 0;
    priority = FIVE;
}

// Parameterized constructor
Patient::Patient(string f, string l)
{
    fname = f;
    lname = l;
}

// Overloading comparison operators
bool operator < (const Patient &one, const Patient &two)
{
    if (one.priority == two.priority)
        if (two.find_early(one, two))
        {
            return true;
        }
        else
        {
            return false;
        }
    else
    {
        return (one.priority < two.priority);
    }
}

bool operator > (const Patient &one, const Patient &two)
{
    if (one.priority == two.priority)
        if (one.find_early(one, two))
        {
            return true;
        }
        else
        {
            return false;
        }
    else
    {
        return (one.priority > two.priority);
    }
}

bool operator == (const Patient &one, const Patient &two)
{
    return ((one.priority == two.priority) &&
            (one.get_time() == two.get_time()));
}

// Print the patient
ostream & operator << (ostream &out, const Patient &p)
{
    out << p.fname << " " << p.lname << endl;
    out << ((p.head_wound) ? "Head wound\n" : "");
    out << ((p.chest_pain) ? "Chest pain\n" : "");
    out << "Pulse: " << p.pulse << endl;
    out << "Temp: " << p.temp << endl;
    out << "PRIORITY ";
    if (p.priority == ONE)
    {
        out << 1 << endl;
    }
    else if (p.priority == TWO)
    {
        out << 2 << endl;
    }
    else if (p.priority == THREE)
    {
        out << 3 << endl;
    }
    else if (p.priority == FOUR)
    {
        out << 4 << endl;
    }
    else
    {
        out << 5 << endl;
    }
    return out;
}

void Patient::calculate_priority(bool cp, bool hw, double t, unsigned p,
                                 int a, bool ph)
{
    time_in = a;
    pulse = p;
    temp = t;
    head_wound = hw;
    chest_pain = cp;
    //priority high
    if (ph)
    {
        if ((hw && cp) || (hw && (p < 90)) || (cp && (p < 90)))
        {
            priority = FIVE;
        }
        else if (hw || cp)
        {
            priority = FOUR;
        }
        else if ((p < 90) && (t > 100))
        {
            priority = THREE;
        }
        else if ((p < 90) || (t > 100))
        {
            priority = TWO;
        }
        else
        {
            priority = ONE;
        }
    }
    else
    {
        if ((hw && cp) || (hw && (p < 90)) || (cp && (p < 90)))
        {
            priority = ONE;
        }
        else if ( hw || cp)
        {
            priority = TWO;
        }
        else if ((p < 90) && (t > 100))
        {
            priority = THREE;
        }
        else if ((p < 90) || (t > 100))
        {
            priority = FOUR;
        }
        else
        {
            priority = FIVE;
        }
    }
}

int Patient::get_time() const
{
    return time_in;
}

bool Patient::find_early(Patient one, Patient two) const
{
    if (one.get_time() < two.get_time())
    {
        return true;
    }
    else
    {
        return false;
    }
}
