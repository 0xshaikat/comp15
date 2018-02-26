#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Survivor.h"
using namespace std;

Survivor::Survivor()
{
    first = "Kristaps";
    last = "Porzingis";
    hometown = "Liepaja";
    state = "New York";
    age = 22;
    s_id = 0;
}//end constructor

Survivor::Survivor(string f, string l, string c, string s, int a)
{
    first = f;
    last = l;
    hometown = c;
    state = s;
    age = a;
}//end parameterized constructor

int Survivor::get_age()
{
    return age;
}//end get_age()

int Survivor::get_s_id()
{
    return s_id;
}
void Survivor::print(ostream &os)
{
    os << first << " " << last << endl;
    os << "hometown: " << hometown << ", " << state << endl;
    os << "age: " << age << endl;
    //os << "id: " << s_id << endl;
}//end print
void Survivor::generate_n_survivor(ifstream &infile, int n)
{
    string f;
    string fi;
    string l;
    string c;
    string s;
    int a = 0;
    int count = 0;
    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, f))
    {
        if (count == n)
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
}//end generate_n_survivor

void Survivor::generate_next_survivor(ifstream &infile)
{
    string f;
    string fi;
    string l;
    string c;
    string s;
    int a = 0;
    int count = 0;
    infile.clear();
    infile.seekg(0, ios::beg);
    while (getline(infile, f))
    {
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

void Survivor::set_name(string f, string l)
{
    first = f;
    last = l;
}//end set_name

bool operator == (const Survivor &s, const Survivor &s1)
{
    return (s.first == s1.first && s.last == s1.last);
}//end ==

bool operator < (const Survivor &s, const Survivor &s1)
{
    if (s.last == s1.last)
    {
        return (s.first < s1.first);
    }
    return (s.last < s1.last);
}//end <

bool operator > (const Survivor &s, const Survivor &s1)
{
    if (s.last == s1.last)
    {
        return (s.first > s1.first);
    }
    return (s.last > s1.last);
}//end >
