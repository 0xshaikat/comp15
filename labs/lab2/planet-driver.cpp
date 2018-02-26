#include "LinkedList.h"
#include <iostream>
using namespace std;

// Function to reverse a linked list
void reverse_list(LinkedList &, LinkedList &);

// User string to stop entering planets
const string STOP = "done";

int main()
{
    // Make a list of planets and prompt user for names
	LinkedList planets;
	string name;
	do
	{
		cout << "Enter a planet (or \"done\" to stop)\n";
		cin >> name;
        cout << endl;

		if(name != STOP)
		{
			Planet p(name);
			planets.insert_planet(p);
		}
	} while (name != STOP);


    // Print in default order (backwards)
    cout << "List of planets, default:\n";
    planets.print(cout);	

    //Print in correct order (reverse)
    LinkedList correct_order;
    reverse_list(planets, correct_order);
    cout << "List of planets, correct order:\n";
    correct_order.print(cout);

    return 0;	
}

// YOUR CODE HERE
// This function should take the elements of l
// and put them in reverse order into l2
// No need to return anything; both are passed by reference
void reverse_list(LinkedList &l, LinkedList &l2)
{
  //declare temp planet to store NodeTypes from l
  Planet tmp;

  //traverse l and insert into l2
  for (int i = 0; i < l.get_length(); i++)
    {
      tmp = l.get_next_planet();
      l2.insert_planet(tmp);
    }//end for 
}//end reverse_list
