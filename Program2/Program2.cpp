//Nikolay Nikolov, CS162
//Program 2

# include <iostream>
# include <cctype>
# include <iomanip>
# include <cstring>
# include <cstdlib>


using namespace std;

// Constants for the numbers from 1-10 in Greek

// 1st function for this program is main_menu 

// On top of main is placed  the prototype of the function.

//Did you know that the word prototype is Greek ? Yes, it is . 
//Protos- means first and typos- means kind , thus the word prototype means 
// the first of its kind. You are welcome. 

//Protype main_menu

void main_menu(char name[]);
int level1(int& points);




int main()
{
	int i;
	char name [21];
	char response;
	int points=0;
	char answer[21];
	// Calling the function main menu

	main_menu(name);

	cout<< "Are you ready? \n" ;
	cout<<endl;
	cout<<"Type [y/n]"<<endl;
	cin>>response;
	cin.ignore(100,'\n');

	if (response=='y' || response=='Y')
	{
		cout << string(60, '\n');
	}

	else 
		cout<<"Good bye!"<<endl;

	//Calling the function level1
	cout<< "Welcome to Level 1 \n" ;

	level1(points);

	return 0;
}



//Main menu function
void main_menu(char name[])

{


 char list[20][20]={"ena","deo","tria","tessera","pente","exi","efta","octo","enia","deka"};
 char list1[20][20]={"one","two","three","four","five","six","seven","eight","nine","ten"};


	int i;

	cout<<"Opa! Enter your name please : \n";

	cin.get(name,100,'\n');
	cin.ignore(100,'\n');

	cout<<"Hi"<<"  "<<name<<endl; 
	cout<<"Let's play  !\n" ;
	// Rules of the game

	cout<<"We are going to start with Level 1 \n";
	cout<<endl;
	cout<<"I am going to show you a word on the screen \n" ;
	cout<<endl;
	cout<<"That represents a number in Greek. \n" ;
	cout<<endl;
	cout<<"You have to type the correct word in English. \n";
	cout<<endl;
	cout<<"Don't worry about lower or upper case . \n";
	cout<<" Just type the word " <<endl;
	cout<<endl;
	cout<<" A quick introduction, I will display the list with the numbers \n" ;
	cout<<endl;
	// Display a list 
	cout<<"Greek" <<"\t"<<"English"<<endl;
	for (i=0;i<11;i++)
		cout<<list[i]<<"\t"<<list1[i]<<endl;


}
//Level 1
int level1(int& points)


{	
	int i;	
	int j;
	char  answer[20];

	char list[20][20]={"ENA","DYO","TRIA"};

	char lista[20][20]={"TESSERA", "PENTE","EXI"};

	char listb[30][30]={"EFTA","OCTO","ENIA","DEKA"};

	char list1[20][20]={"ONE","TWO","THREE"};

	char list2[20][20]={"FOUR","FIVE","SIX"};

	char list3[30][30]={"SEVEN","EIGHT","NINE","TEN"};



	for (i=0;i<3;i++)

	{ 
		cout<<"Your word is : " << endl;
		cout<<"\t\t"<< list[i] <<endl;		
		cout<<"What number it is?"<<endl;
		cin.get(answer,10,'\n');
		cin.ignore(100,'\n');

		for (j=0;j<3;j++)
		{		
			if(toupper(answer[i])==list1[i][j])
			{
				points=points+1;
				cout<<"Good job!" <<endl;
				cout<<"You have   "<<points<<"  points"<<endl;
				}			
				
						
		cout<<endl;
		}
	
	}
	for (i=0;i<3;i++)

	{ 
		cout<<"Your word is : " << endl;
		cout<<"\t\t"<< lista[i] <<endl;		
		cout<<"What number it is?" <<endl;
		cin.get(answer,10,'\n');
		cin.ignore(100,'\n');

		for (j=0;j<3;j++)
		{		
			if(toupper(answer[i])==list2[i][j])
			{

				points=points+1;
				cout<<"Good job!" <<endl;
				cout<<"You have   "<<points<<"  points"<<endl;			
			}
		cout<<endl;
		}

	}


	for (i=0;i<4;i++)

	{ 
		cout<<"Your word is : " << endl;
		cout<<"\t\t"<< listb[i] <<endl;		
		cout<<"What number it is? " <<endl;
		cin.get(answer,10,'\n');
		cin.ignore(100,'\n');

		for (j=0;j<4;j++)
		{		
			if(toupper(answer[i])==list3[i][j])
			{

				points=points+1;
				cout<<"Good job!" <<endl;
				cout<<"You have   "<<points<<"  points"<<endl;			
			}
		cout<<endl;
		}

	}

	

return points;

}
