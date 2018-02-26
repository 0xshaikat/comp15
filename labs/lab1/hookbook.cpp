//Shaikat Islam
//January 26th, 2018
//Lab 1 (ADT: ArrayList)
//COMP15

#include <iostream>
#include <ArrayList.h>
#include <Pirate.h>
using namespace std;

int main()
{
  //Step One: Make Some Pirates

  //instantiate five new Pirate objects
  Pirate one("Blackbeard");
  Pirate two("Captain Kidd");
  Pirate three("Captain Hook");
  Pirate four("Smokey");
  Pirate five("Bram Cohen");

  //instantiate new ArrayList
  ArrayList arr;

  //add pirates to new ArrayList
  arr.insert_pirate(one);
  arr.insert_pirate(two);
  arr.insert_pirate(three);
  arr.insert_pirate(four);
  arr.insert_pirate(five);

  //print ArrayList
  arr.print();

  //Step Two: Make a BUNCH of Pirates
  
  //File IO
  ifstream infile;
  infile.open("pirate_names.txt");

  //error check
  if (!infile.is_open())
    {
      cerr << "Error opening file\n";
      return 1;
    }//end if
  
  //iterate 
  for (int i = 0; i < 200; i++)
    {
      Pirate tmp;
      tmp.generate_pirate_name(infile, 698);
      tmp.assign_pirate_id();
      tmp.print();
      arr.insert_pirate(tmp);
      if(arr.is_full())
	{
	  cout << "Array is full! No more pirates.\n";
	  return 0;
	}//end if
    }//end for
  
  //print arr
  arr.print();

  //return statement
  return 0;

}//end main()
