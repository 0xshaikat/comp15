#include <iostream>
#include <fstream>
#include <sstream>
#include "Survivor.h"
using namespace std;

int main()
{
    //initialization
    Survivor s;
    cout << "Constructor: SUCCESS\n";
    ostream & objOstream = cout;
    s.print(objOstream);
    cout << endl;
    cout << "Print: SUCCESS\n";
    ifstream infile;
    infile.open("castaways.txt");
    s.generate_next_survivor(infile);
    s.print(objOstream);
    cout << "Generate next survivor: SUCCESS\n";
    s.generate_next_survivor(infile);
    s.print(objOstream);
    cout << "Generate next survivor: SUCCESS\n";
    s.generate_next_survivor(infile);
    s.print(objOstream);
    cout << "Generate next survivor: SUCCESS\n";
    Survivor s1("J.", "Cole", "Fayeteville", "NC", 33);
    Survivor s2("Kendrick", "Lamar", "Compton", "CA", 30);
    Survivor s3("Kendrick", "Lamar", "Compton", "CA", 30);
    cout << "Equality Tests:\n";
    s1.print(objOstream);
    s2.print(objOstream);
    s3.print(objOstream);
    if (s1 > s2)
    {
        cout << "Is J. Cole greater than Kendrick Lamar?\n";
        cout << "FAILED" << endl;
    }//end if
    else
    {
        cout << "Is J. Cole greater than Kendrick Lamar?\n";
        cout << "NAH\n";
        cout << "SUCCESS" << endl;
    }//end else
    if (s1 < s2)
    {
        cout << "Is J. Cole less than Kendrick Lamar?\n";
        cout << "Yeah, alphabetically.\n";
        cout << "SUCCESS" << endl;
    }//end if
    else
    {
        cout << "Is J. Cole greater than Kendrick Lamar?\n";
        cout << "FAILED" << endl;
    }//end else
    if (s1 == s2)
    {
        cout << "Is J. Cole equal to Kendrick Lamar?\n";
        cout << "FAILED" << endl;
    }//end if
    else
    {
        cout << "Is J. Cole equal to Kendrick Lamar?\n";
        cout << "NAH\n";
        cout << "SUCCESS" << endl;
    }//end else
    if (s3 == s2)
    {
        cout << "Is Kendrick Lamar equal to Kendrick Lamar?\n";
        cout << "SUCCESS!" << endl;
    }//end if
    else
    {
        cout << "Is Kendrick Lamar equal to Kendrick Lamar?\n";
        cout << "FAILED" << endl;
    }//end else


}//end main
