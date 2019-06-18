// Nikolay Nikolov, CS 162, Program 3

#include<iostream>
#include<cstring>
#include<cctype>
#include<cstring> 
#include<fstream>


const int SIZE =21; // Constant

struct myCS  // Struct----------------------
{
	int number;
	char type[SIZE];
	char text[700];
	char complete;

};// Struct-------------------------------------


using namespace std;

//Prototypes ------------------------------------------------------------------------------------
void write_to_file(myCS & out);

void m_menu(int & response ); // Main menu function call

void add_question(myCS questions[],int &counter);  // Add question function that utilizes the struct

void read_question(myCS questions[], int & counter); // Function to read question from a file 

void read(myCS questions[], int & counter); // Function to display the menu with options 

void read_all_questions(myCS questions[], int & counter); // Function that reads all the questions 

void modify(myCS questions[], int & counter ) ; // Function to modify the questions 

void write_to_file(myCS out[],int & counter ); // Function to write on a file 

void read_all_type( myCS question[], int & counter );// <--- Function  to read all questions by type 

void read_all_complete( myCS question[], int & counter );// <--- Function to read all complete questions

// Prototypes -------------------------------------------------------------------------------------

/* How many programmers does it take to change a light bulb?
A: None. It’s a hardware problem.

 */



int main ()// Main--------------------------------------------------------------------------------

{	
	int response;
	int counter=0;

	myCS question[20]; // Array of questions 

	read_question(question,counter); // Reads all the question from the file 

	while (response !=4) // While loop that brings the user to the main menu 
	{

		m_menu(response); // Calling the function m_menu

		if (response == 1)
		{
			add_question ( question, counter ); // Calling the add_question function to add a question
		}
		if (response == 2)
		{
			read( question , counter ); // Calling the read fuction to display a menu for displaying questions 
		}
		if (response == 3)
		{
			modify( question,counter ) ; // Calling the modify function to modify a question 
			write_to_file ( question , counter ); // Saving the modified question (overwrting )
		}
		if (response != 4)
		{
			cout << " Press 4 to quit and any  other number to go back to the main menu  " << endl;
			cin >> response;
			cin.ignore(100,'\n');
		}
	}
	return 0;
}
// End of main---------------------------------------------------------------------------------

void  m_menu(int & response)// Main menu function begins here-----------------------------------

{

	cout << "\033[2J\033[1;1H";
	cout << "\t\t\t" << "\t \t  Welcome! \n";
	cout << "\t\t\t"  << "Your future self developed this program \n";
	cout << endl;
	cout << "\t\t\t" << "For you to practice C++ during the summer \n"; 
	cout << endl;
	cout << endl;
	cout << "\t\t\t" << "You have 3 options to choose from \n";
	cout << endl;
	cout << endl;

	// Display all the available options

	cout << "\t\t\t" << "\t--------------"  << "-----------------------" << "-------------------------" << endl; 
	cout << "\t\t\t" << "\t|Add Question|"  << "|  Display a Question |" << "|   Modify a Question   |" << endl ;
	cout << "\t\t\t" << "\t--------------"  << "-----------------------" << "-------------------------" << endl;
	cout << "\t\t\t" << "\tTo Add a Question press 1" << endl;
	cout << "\t\t\t" << "\t \t To Display Questions press 2 " << endl ;
	cout << "\t\t\t" << "\t \t \t To Modify a Question press 3 " << endl ;
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

// Before you continue please read about  " Jon Skeet " 

/*
   These are written in the third person so as not to disrupt the style of the thing. But hey, as we all know, Jon Skeet can make 1 == 3 anyway, so it makes no difference.

   Jon Skeet is immutable. If something's going to change, it's going to have to be the rest of the universe.
   Jon Skeet's addition operator doesn't commute; it teleports to where he needs it to be.
   Anonymous methods and anonymous types are really all called Jon Skeet. They just don't like to boast.
   Jon Skeet's code doesn't follow a coding convention. It is the coding convention.
   Jon Skeet doesn't have performance bottlenecks. He just makes the universe wait its turn.
   Jon Skeet is the only person who has ranked higher than Jon Skeet in the SO all-time rep league.
   Users don't mark Jon Skeet's answers as accepted. The universe accepts them out of a sense of truth and justice.

 */



// Ok, hope I made you smile so far , there are no more jokes throughout the rest of the code.


// Function "add_question" starts here----------------------------------------------

void add_question(myCS question[], int & counter)

{
	//myCS question;
	char response1;
	do {
		cout << "\033[2J\033[1;1H" ;// clears the screen 
		//cout << "Please insert the number of the question \n";
		//cin >> question[counter].number;
		//cin.ignore (100,'\n');

		question[counter].number = counter + 1;

		cout << "Please insert the type of the question \n";
		cin.get(question[counter].type,100,'\n');
		cin.ignore (100,'\n');

		cout << "Please type the text of the question up to 700 chars \n";
		cin.get(question[counter].text,700,'\n');
		cin.ignore (700,'\n');


		cout << "If the question is completed type (c) or if incompleted type (i) \n" ;
		cin >> question[counter].complete;
		cin.ignore (100,'\n');

		write_to_file(question[counter]);

		++counter; // counter to keep track of the questions 

		cout << "Would you like to add another question? [y/n] \n ";
		cin >> response1;
		cin.ignore (100,'\n');

	} while (tolower(response1 == 'y'));




}// Function ends here-----------------------------------------------------------------------------------





// Function "write_to_file" starts here------------------------------------------------------------------
void write_to_file(myCS & out)// Saves to a file to questions
{
	ofstream myquest; // Write on  file 
	myquest.open("practice.txt",ios::app);// Create file 

	if (myquest)// Test if it was successful
	{		 
		myquest << out.number << ":" << out.type << ":"  << out.text <<":";
		myquest << out.complete << endl;
		myquest.close();
		myquest.clear(); 		

	} 

}

// Function ends here-------------------------------------------------------------------------------------

// Function to overwite after the file has been modified -------------------------------------------------
void write_to_file(myCS out[],int & counter )// Save file after the file has been modified 

{
	ofstream myquest; // Write on file 
	myquest.open("practice.txt"); // Create a file 

	if (myquest)
	{		 

		for ( int i=0 ;i<counter ;++i)// Loop through the struct 
		{
			myquest << out[i].number << ":" << out[i].type << ":"  << out[i].text <<":";
			myquest << out[i].complete << endl;
		}
		myquest.close();
		myquest.clear(); 		

	} 

}

// Function ends here ------------------------------------------------------------------------------------



// Function " read_question" starts here------------------------------------------------------------------

void read_question(myCS question[],int &counter ) //<--- Read question, the function reads all the questions from the file 

{
	ifstream myquest;
	myquest.open("practice.txt");

	if (myquest)
	{
		myquest >> question[counter].number;
		myquest.ignore(100, ':');

		while (!myquest.eof())// Tests if the file has ended 
		{

			myquest.get(question[counter].type,SIZE,':');
			myquest.ignore(100, ':');

			myquest.get(question[counter].text,700,':');
			myquest.ignore(700, ':');

			myquest >> question[counter].complete;
			myquest.ignore(100, '\n');

			++counter;

			myquest >> question[counter].number;
			myquest.ignore(100, ':');
		}
		myquest.close();// close the file 
		myquest.clear(); // flush the buffer
	}

}

//<--- Function "read_question"  ends here ------------------------------------------------------------




//-----------------------------------------------------------------------------------------------------
void read (myCS question[],int & counter )// <---Function " read" starts here--------------------------

{
	cout << "\033[2J\033[1;1H"; // clears the screen 
	int response;
	// Menu options 
	cout << endl;
	cout << "\t\t\t" <<  "------------------------" << "---------------------------" << "-------------------------------" << endl;
	cout << "\t\t\t" <<  "|Display ALL Questions|" << "|Display Questions by type|" << " |Display completed questions| " << endl;
	cout << "\t\t\t" <<  "------------------------" << "---------------------------" << "------------------------------" << endl;
	cout << "\t\t\t" <<  "To Display  ALL Questions press 1" << endl;

	cout << "\t\t\t" << "\t\tTo Display  a Question by type  press 2" << endl;

	cout << "\t\t\t" << "\t\t\tTo Display  only  a completed  Question press 3" << endl;

	cout << "\t\t\t" << "Please type 1 , 2 , or 3 to make a choice from the menu " << endl;
	cout << "\t\t\t" << " To quit press 5 " << endl;
	cin >> response;
	cin.ignore(100,'\n');

	// Calling the functions according to the user's input
	if (response == 5)
	{
		cout << "Have a nice day ! " << endl;

	}
	else if (response == 1)
	{	
		read_all_questions(question, counter);
	}	
	else if ( response == 2  )
	{
		read_all_type(question , counter ) ; 
	}
	else if ( response == 3 )
		read_all_complete ( question , counter ) ;

}// Function "read" ends here --------------------------------------------------------------------------

void read_all_type( myCS question[], int & counter )// <--- Function read_all_questions starts here

{
	char response2; 
	char temp[SIZE]; // the user's input


	do {
		cout << "\033[2J\033[1;1H";// clears the screen 
		cout << "Which type ? " << endl;
		cout << "Please type exactly as displayed , 'if statement', 'loops', 'structs' , 'class', 'arrays' " << endl;
		cin.get(temp, SIZE, '\n');
		cin.ignore(100, '\n');
		cout << "---------------------------------------------\n";
		for (int i=0;i < counter ; ++i)
		{
			if (strcmp (temp, question[i].type) == 0) 
			{
				cout << question[i].number << ":" << question[i].type << endl;
				cout << question[i].text << ":" << question[i].complete << endl;
				cout << "---------------------------------------------\n";

			
			}
		}

		
				cout << " Would you like to try again [y/n]? " << endl;
				cin >> response2 ;
				cin.ignore(100,'\n');
		
	}while (tolower(response2 == 'y' ));
}// <----- Function read_all_questions ends here----------------------------------------------------------




// read_all_questions function-------------------------------------------------------------------------

void read_all_questions( myCS question[], int & counter )// <--- Function read_all_questions starts here

{
	cout << "\033[2J\033[1;1H";// clears the screen
	cout << "Here are all the questions you have so far " << endl;
	cout << "---------------------------------------------\n";
	for (int i=0;i < counter ; ++i)

	{
		cout << question[i].number << ":" << question[i].type << endl;
		cout << question[i].text << ":" << question[i].complete << endl;
		cout << "---------------------------------------------\n";

	}

}// <----- Function read_all_questions ends here---------------------------------------------------------



// ----function that modifies the questions --------------------------------------------------------------------------------
void modify(myCS questions[], int & counter ) 

{
	int num=0;
	char response;
	read_all_questions(questions, counter );
	do // do- while loop  to make sure that the user types a number between 1-20
	{	
		cout << "Which question would you like to modify " << endl;// the user is prompted to select a question 
		cout << "Please type int from 1-20 " << endl ; 

		cin >> num;
		cin.ignore(100,'\n');

	}while (num <1 || num >20 );

	cout << " Do you want to change type [y/n] \n"; // The user is prompted to choose what to modify
	cin >> response;	
	cin.ignore(100, '\n');
	if ( response == 'y')
	{ 

		cout << " What is new type ? " << endl;
		cin.get(questions[num-1].type,SIZE, '\n');// num -1 because the questions start from 1 rather where the array begins 
		cin.ignore(100, '\n');
	}

	cout << " Do you want to change question text [y/n] \n";
	cin >> response;
	cin.ignore(100, '\n');
	if ( response == 'y')
	{ 

		cout << " What is new question text ? " << endl;
		cin.get(questions[num-1].text,700, '\n');
		cin.ignore(700, '\n');
	}

	cout << " Do you want to change complete status [y/n] \n";
	cin >> response;	
	cin.ignore(100, '\n');
	if ( response == 'y')
	{ 

		cout << " What is new status? " << endl;
		cin >> questions[num-1].complete;
		cin.ignore(100, '\n');
	}

}//function ends here ------------------------------------------------------------------------------------------------------ 

//----------------------------------------------------------------------------------------------------------------
void read_all_complete( myCS question[], int & counter )// <--- Function read_all_complete  starts here (reads all the complete questions)
{
	cout << "\033[2J\033[1;1H"; // clears the screen 
	cout << "Here are all the complete questions you have so far " << endl; 
	cout << "---------------------------------------------\n";
	for (int i=0;i < counter ; ++i)// a for loop that will go through the entire stuct a display the questions

	{
		if (question[i].complete == 'c')
		{
			cout << question[i].number << ":" << question[i].type << endl;
			cout << question[i].text << ":" << question[i].complete << endl;
			cout << "---------------------------------------------\n";
		}
	}
}
//--------------------------------------------------------------------------------------------------------------
