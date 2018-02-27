#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Survivor.h"
using namespace std;

// constructor
Survivor::Survivor()
{
    // KRISTAPPPPPSS
    first = "Kristaps";
    last = "Porzingis";
    hometown = "Liepaja";
    state = "New York";
    age = 22;
    s_id = 0;
}//end constructor

//parameterized constructor
Survivor::Survivor(string f, string l, string c, string s, float a)
{
    first = f;
    last = l;
    hometown = c;
    state = s;
    age = a;
}//end parameterized constructor

// returns age
float Survivor::get_age()
{
    return age;
}//end get_age()

// returns id num
int Survivor::get_s_id()
{
    return s_id;
}

// prints survivor
void Survivor::print(ostream &os)
{
    os << first << " " << last << endl;
    os << "hometown: " << hometown << ", " << state << endl;
    os << "age: " << age << endl;
    //os << "id: " << s_id << endl;
}//end print

// generates line based on next int
void Survivor::generate_n_survivor(ifstream &infile, int n)
{
    // vars to hold info
    string f;
    string fi;
    string l;
    string c;
    string s;
    float a = 0;
    int count = 0;
    infile.clear();
    infile.seekg(0, ios::beg);

    //read into getline
    while (getline(infile, f))
    {
        // if count matches n, get the line
        if (count == n)
        {
            // parse string into diff vars
            istringstream iss(f);
            iss >> fi;
            iss >> l;
            iss >> c;
            iss >> s;
            iss >> a;
            break;
        }//end if
        count++;
    }//end while
    first = fi;
    last = l;
    hometown = c;
    state = s;
    age = a;
}//end generate_n_survivor

// generate next survivor based on current Survivor object id
void Survivor::generate_next_survivor(ifstream &infile)
{
    string f;
    string fi;
    string l;
    string c;
    string s;
    float a = 0;
    int count = 0;
    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, f))
    {
        // based on id
        if (count == s_id)
        {
            istringstream iss(f);
            iss >> fi;
            iss >> l;
            iss >> c;
            iss >> s;
            iss >> a;
            break;
        }//end if
        count++;
    }//end while
    first = fi;
    last = l;
    hometown = c;
    state = s;
    age = a;
    s_id++;
}//end generate_next_survivor()

// set name for survivor object
void Survivor::set_name(string f, string l)
{
    first = f;
    last = l;
}//end set_name

// equality operator
bool operator == (const Survivor &s, const Survivor &s1)
{
    return (s.first == s1.first && s.last == s1.last);
}//end ==

// < operator
bool operator < (const Survivor &s, const Survivor &s1)
{
    if (s.last == s1.last)
    {
        return (s.first < s1.first);
    }
    return (s.last < s1.last);
}//end <

// > operator
bool operator > (const Survivor &s, const Survivor &s1)
{
    if (s.last == s1.last)
    {
        return (s.first > s1.first);
    }
    return (s.last > s1.last);
}//end >
