#include <iostream> 
#include <cctype>
#include<cstring>
#include<fstream>

// Nikolay Nikolov, CS 162, Program # 5 , May 20, 2016
/* Purpose of the Program 

   The purpose of the program is to keep track of the available doggy parks in the Portland area.
 The program with store the name of the park, location, description, if it is fenced ,size of it and a rating from Google.
 The user will be able to either add a new park with all the available information, either retrieve information about a park
 by searching for the name of the park, and last display all available parks.
 This program uses Linear Liked Lists .

Hardware ~ The part of a computer that you can kick.

Why did the programmer quit his job?

~Because he didn't get arrays.( a raise )





 */

using namespace std;

class park // creating the class for the park's feautures 
{
	public:
		park(); // default constructor 
		~park();
		void insert(char*,char*, char*,char*,char*,char*);
		bool find_info();
		void disp();
		void write_to_file(ofstream & );
		char* getName();

	private:
		char*name;
		char*location;
		char*description;
		char*fenced;
		char*size;
		char*rating;
};

struct node // creating the node
{
   park data ; 
   node*next;
};

class lll
{ 
	public :
	lll();
	~lll(); 
	void insert(char* , char *, char * , char * ,char * , char *);
	 void display ();
	private :
	node*head; 
};	

const int SIZE=20;

class park_array // class for the parks 
{
	public:
		~park_array();
		park_array();
		void disp();
		void add_park();
		void write_to_file();
		void read_file(); 
		void display_parks();
		void display_info(); 
	private:
		int count;
		lll parkList ;
		park * parks;
		node*head; 
};

void m_menu(int & response ); // Main menu function call
// Algorithm ~ Word used by programmers when ... they do not want to explain what they did.
