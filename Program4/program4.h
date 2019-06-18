#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

// Nikolay Nikolov, CS 162, Program # 4 , May 20, 2016
/* Purpose of the Program 

   The purpose of the program is to keep track of the available doggy parks in the Portland area.
 The program with store the name of the park, location, description, if it is fenced ,size of it and a rating from Google.
 The user will be able to either add a new park with all the available information, either retrieve information about a park
 by searching for the name of the park, and last display all available parks.
 The data for program 4 will be a dynamically allocated array.


 */

using namespace std;

const int SIZE=20;
class park
{
	public:
		park(); // default constructor 
		~park();
		void insert(char*,char*, char*,char*,char*,char*);
		bool find_info();
		void disp();

	private:
		park * next;
		char*name ;
		char*location;
		char*description;
		char*fenced;
		char*size;
		char*rating;
};

class park_array
{
	public:
		~park_array();
		park_array();
		void disp();
		void add_park();
		void write_to_file();
	private:
		int count;
		park*parks;
};


void m_menu(int & response ); // Main menu function call
