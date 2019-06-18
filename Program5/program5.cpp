//Nikolay Nikolov , CS 162

#include "lll.h"



park :: park()//constructor-----------------------------------------------------------------------------------------------
{
	name = NULL;
	location = NULL;
	description = NULL;
	fenced = NULL;
	size = NULL;
	rating = NULL; 
}//-------------------------------------------------------------------------------------------------------------------------


park :: ~park()// destructor -------------------------------------------------------------------------------------------
{
	if ( name )
		delete [] name ; 

	if ( location )
		delete [] location; 

	if ( description )
		delete [] description ; 

	if ( fenced )
		delete [] fenced ;

	if ( size)
		delete [] size; 

	if (rating)
		delete [] rating ; 
}//-------------------------------------------------------------------------------------------------------------------------


//function to insert the park's infromation ------------------------------------------------------------------------------------------------
void park :: insert(char*park_name,char*park_location,char*park_description,char*park_fenced,char*park_size,char*park_rating)
{
	name = new char [strlen(park_name)+1];
	strcpy(name, park_name);

	location = new char [strlen(park_location)+1];
	strcpy(location,park_location);

	description = new char [strlen(park_description)+1];
	strcpy(description, park_description);

	fenced  = new char [strlen(park_fenced)+1];
	strcpy(fenced,park_fenced);

	size = new char [strlen(park_size)+1];
	strcpy(size, park_size);

	rating  = new char [strlen(park_rating)+1];
	strcpy(rating ,park_rating);
}
//--------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------

void park::disp()//Function to display the information-----------------------------------------------------------------------
{
	cout << "The name is " << name << "." << "The location is " << location <<"." << "The description is " << description <<".";
	cout << "The size is " << size << "." << "The rating is " << rating << "." << endl; 
}
//---------------------------------------------------------------------------------------------------------------------------

park_array :: park_array()//constructor-------------------------------------------------------------------------------
{
	count=0;
	parks = new park[SIZE] ;

}
//--------------------------------------------------------------------------------------------------------------------------


park_array :: ~park_array()//destructor-------------------------------------------------------------------------------------
{
	if (parks)
		delete [] parks;
} //----------------------------------------------------------------------------------------------------------------------


// Function "park_array" starts here---------------------------------------------------------------------------------------
void park_array :: add_park ()
{

	char response;
	char name[50] ;
	char location[100];
	char description[500];
	char fenced[20];
	char size[10];
	char rating[10];
	do {//------------Get information from the user ------------------------------------------------------------------------
		cout << "\033[2J\033[1;1H" ;// clears the screen 

		cout << "Please insert the name of the park\n";
		cin.get(name,50,'\n');
		cin.ignore (50,'\n');

		cout << "Please type location of the park in  100 chars \n";
		cin.get(location,100,'\n');
		cin.ignore (100,'\n');


		cout << "Please type the description of the park in 500 chars " ;
		cin.get(description,500, '\n');
		cin.ignore (500,'\n');

		cout << "Please type if the park is fenced " << endl; 
		cout << "If the park is fenced type 'fenced' or 'not-fenced' for not fenced " << endl;
		cin.get(fenced,20,'\n');
		cin.ignore(20,'\n');

		cout << "Please type the size of the park :" << endl;
		cout << "Type 'small', 'medium' , 'large' " << endl;
		cin.get(size,10,'\n');
		cin.ignore(10, '\n');

		cout << "Please type the rating of the park : " << endl;
		cout << "Type 'one', 'two'.. up to 'five' " << endl;
		cin.get (rating,10, '\n');
		//----------------------------------------------------------------------------------------------------------------------------
		parkList. insert (name,location, description, fenced, size, rating) ;

		++count; // counter to keep track of the questions 

		cout << "Would you like to add another question? [y/n] \n ";
		cin >> response;
		cin.ignore (100,'\n');

	} while (tolower(response == 'y') && count < SIZE);// do-while loop --------------------------------------------------
}// Function ends here-----------------------------------------------------------------------------------



void park :: write_to_file(ofstream & mypark)// Saves to a file --------------------------------------------------------------
{
	if (mypark)// Test if it was successful
	{	
		mypark << name << ":" << location << ":"  << description <<":";
		mypark << fenced <<":" << size << endl;
	} 
}//----------------------------------------------------------------------------------------------------------------------------




// Function "write_to_file" starts here--------------------------------------------------------------------------------------
void park_array :: write_to_file()// saves to the file the park's information
{
	ofstream mypark; // Write on  file 
	mypark.open("parks.txt");// Create file 

	if (mypark)// Test if it was successful
	{	
		node*current = head ;
		
		while ( current )
		{	 
			current -> data .write_to_file(mypark);
			current = current -> next ;
		}
		mypark.close();
		mypark.clear(); 		

	} 

}//---------------------------------------------------------------------------------------------------------------------------



// Function ends here---------------------------------------------------------------------------------------------------------
void park_array :: display_parks ()
{
		parkList.display();
}//--------------------------------------------------------------------------------------------------------------------------

char* park::getName(){
	return name;
} 

//---------------------------------------------------------------------------------------------------------------------------
void park_array :: display_info()
{
	char response[100];
	cout <<"Please enter the name of the park " << endl; 
	cin.get (response,100,'\n');  
	cin.ignore(100,'\n');

	for (int i = 0;i < count;++i)
	{ 
		if (strcmp (response ,parks[i].getName()) == 0)
		{	parks[i].disp();				
			return ;

		} 

	}

}
//---------------------------------------------------------------------------------------------------------------------------

void park_array :: read_file ()
{

	char name[50] ;
	char location[100];
	char description[500];
	char fenced[20];
	char size[10];
	char rating[10];

	ifstream myparks;
	myparks.open("parks.txt");
	myparks.peek();	
	while(!myparks.eof()) 
	{
		myparks.get(name,50,':');
		myparks.ignore (50,':');

		myparks.get(location,100,':');
		myparks.ignore (100, ':');	
	
		myparks.get(description,500,':');
		myparks.ignore(500,':');

		myparks.get(fenced,20,':');
		myparks.ignore(20,':');

		myparks.get(size,10,':');
		myparks.ignore(10,':');

		myparks.get(rating,10);
		myparks.ignore(10,'\n');

		parks[count]. insert(name,location, description, fenced, size, rating) ;
		++count;
		myparks.peek();
	}
	myparks.close();
	myparks.clear();

}


