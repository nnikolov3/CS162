// Nikolay Nikolov, CS 162, Program 4

#include "lll.h"

int main ()// Main--------------------------------------------------------------------------------
// Real Programmers count from 0. 

// Chuck Norris can take a screenshot of his blue screen.

// UNIX is user firendly 

// It's just very particular about who its friends are.





{	
	int response;
	int counter=0;

	
	park_array myparks;
	myparks.read_file();

	while (response !=4) // While loop that brings the user to the main menu 
	{

		m_menu(response); // Calling the function m_menu

		if (response == 1) 
		{
			myparks.display_parks();				
		}
		if (response == 2)
		{
			myparks.display_info();
		}
		if (response == 3)
		{
			myparks.add_park();
		}
		if (response != 4)
		{
			cout << " Press 4 to quit and any  other number to go back to the main menu  " << endl;
			cin >> response;
			cin.ignore(100,'\n');
		}
	}

	myparks.write_to_file();// Write to file 

	return 0;
}
// End of main---------------------------------------------------------------------------------

void  m_menu(int & response)// Main menu function begins here-----------------------------------

{

	cout << "\033[2J\033[1;1H";

	cout << "\t\t\t" << "You have 3 options to choose from \n";
	cout << endl;
	cout << endl;

	// Display all the available options

	cout << "\t\t\t" << "\t---------------"  << "-----------------------" << "--------------------------" << endl; 
	cout << "\t\t\t" << "\t|Display parks|"  << "|  Display information |" << "|   Add Park		   |" << endl ;
	cout << "\t\t\t" << "\t---------------"  << "-----------------------" << "--------------------------" << endl;
	cout << "\t\t\t" << "\tTo Display all parks press 1" << endl;
	cout << "\t\t\t" << "\t \t To Display information about parks press 2 " << endl ;
	cout << "\t\t\t" << "\t \t \t To Add a park press 3 " << endl ;
	cout << "\t\t\t"<< endl;

	cout << "\t\t\t"<< "Press 1, 2 or 3 : \n";
	cout << "To quit press 4 " << endl; // If the user wants to quit 
	cin >> response;
	cin.ignore(100,'\n');

	if (response == 4)
	{
		cout << "Have a nice day ! " << endl;
	}

	while (response > 4 || response < 1 )
	{
		cout << "Press 1, 2 or 3 : \n";
		cout << "To quit press 4 " << endl;
		cin >> response;
		cin.ignore(100,'\n');
	}
} // Main menu function ends here--------------------------------------------------
