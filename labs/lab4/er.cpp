/*
 * er.cpp
 *
 * COMP15
 * Spring 2018
 * Lab 4
 *
 * Dr. McDreamy? Hawkeye is paging you!
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Patient.h"
#include "MinHeap.h"
#include "Queue.h"
using namespace std;

const string PATIENT_FILE = "patients.txt";

int read_in_patients(Queue<Patient> &, string);

int main()
{
    Queue<Patient> patients;
    int count = read_in_patients(patients, PATIENT_FILE);
    cout << "read in " << count << " patients\n";
    //declare MinHeap
    MinHeap <Patient> mp;

    //insert patients into MinHeap
    for (int i = 0; i < count; i++)
      {
	mp.insert_item(patients.dequeue());
      }

    //print most prioritized patient
    cout << "Most important patient to see:\n";
    cout << mp.extract() << endl;
    count--;

    //extract rest of the patients in priority order
    for (int j = 0; j < count; j++)
      {
	cout << mp.extract() << endl;
      }

    //How many patients left in the queue?
    cout << "After all this, I have " << count
	 << " patients left in the queue" << endl;
    return 0;
}

// Function read_in_patients
// Parameters: Queue of Patients by reference, string for file
// Returns: number of patients read in
// Does: Enqueues patients in order
int read_in_patients(Queue<Patient> &p, string filename)
{
    ifstream infile;
    infile.open(filename.c_str());
    if (!infile.is_open())
        return 0;

    string fname, lname;
    char ins, head;
    unsigned pulse;
    double temp;

    int count = 0;
    while (!infile.eof())
    {
        infile >> fname;
        if (fname == "-1")
            return count;
        infile >> lname >> ins >> head >> pulse >> temp;

        Patient pat(fname, lname);
        pat.calculate_priority((ins == 'C' ? true : false), 
                               (head == 'H' ? true : false),
                               temp, pulse);

        try
        {
            p.enqueue(pat);
        }
        catch (FullQueue exception)
        {
            return 0;
        }

        count++;
    }
    infile.close();
    return count;
}


