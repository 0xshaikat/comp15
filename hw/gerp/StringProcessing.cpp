// Shaikat Islam
// COMP15
// Phase I
// 17-04-2018

#include <iostream>
#include <string>
using namespace std;

//function definition
string process_string(string);
bool invalid_character(char);

//int main()
//Purpose: run program
//Returns: int
//Parameters: none
int main()
{
    string s;
    string r;

    //continuous input
    while (cin >> s)
    {
        r = process_string(s);
        cout << r << endl;
        cout << endl;
    }// end while
}// end main

//process_string
//Purpose: remove leading and trailing non-alphanum chars from a string
//Returns: string
//Parameters: string
string process_string(string s)
{
    //size of string
    size_t len = s.length();

    //remove the invalid chars at front
    while(!invalid_character(s[0]))
    {
        if (len <= 0)
        {
            return "";
        }// end if
        s.erase(0,1);
        len--;
    }//end while

    //remove the invalid chars at the bacl
    while(!invalid_character(s[len]))
    {
        if (len <= 0)
        {
            return "" ;
        }// end if
        s.erase(len, 1);
        len--;
    }// end while

    //return processed string
    return s;
}// end process_string

//invalid_character
//Purpose: return false if invalid alphanum, true otherwise
//Returns: bool
//Parameters: char
bool invalid_character(char c)
{
    if (c > 64 && c < 91)
    {
        return true;
    }// end if
    if (c > 96 && c < 123)
    {
        return true;
    }// end if
    if (c > 47 && c < 58)
    {
        return true;
    }// end if
    return false;
}// end invalid_character
