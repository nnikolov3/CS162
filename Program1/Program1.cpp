//Nikolay Nikolov, CS 162 


# include <iostream>
#include<cctype>
# include <iomanip>
using namespace std;


int main()



{
	//Step 1
	char  choice; //For option 1 and 2
	char type;
	int  option;
	int Convert1,Convert2,Convert3;
	int cType;
	float US;
	float CNY;
	float amount;// Amount of currency 
	float  UStoCNY=6.50824;// Exchange rate for US dollars to CNY 
	float  CNYtoUS=0.15365;// Exhange rate for CNY to US dollars
	float totalUS; //Converted amount in US dollars 
	float totalCNY; // COnverted amount in CNY 
	int bills100;// # of Bills for 100's
	int bills50; // # of Bills for 50's
	int bills20;// # of Bills for 20's
	int bills10; // # of Bills for 10's
	int bills5; // # of Bills for 5's
	int bills1; // # of Bills for 1's
	int CNY100;
	int CNY50;
	int CNY20;
	int CNY10;
	int CNY5;
	int CNY1;
	float change;






	cout<< "Welcome!"<<endl ;// Beginning of the program ,and greeding the user 
	cout<<endl;
	cout<< " I am a program from 1988!"<< endl;
	cout<< " I am  simple but powerful !" << endl;
	cout<<endl;






	// The program offers 3 choices 
	cout<< "You can do 3 things:" << endl;
	cout<<"If you press 1, you can convert currency US dollars->CNYuan or CNYuan->US dollars. \n";
	cout<<"If you press 2, you can convert CNYuan into bill denominations. " << endl;
	cout<<"If you press 3, you can convert CNYuan bill denominations to US dollars currency."<< endl;
	cout<< "Let's get started!"<<endl;
	cout<< endl;
	cout<<endl;

	 cout<<"Please type 1,2,or 3 \n";
	cin>>cType;
	cin.ignore(20,'\n');

		
	while((cType!=1) ||(cType!=2) || (cType!=3))
	{ 
		
		if(cType==1)						// Choice 1 to convert currency
		{	



			do {							//Using do-while loop

				cout<<"Please type the amount you want to convert  \n";
				cin>>amount;
				cin.ignore(20,'\n');
				if( amount<0)
				{
					cout<<" Please type a positive integer number" <<endl;
					cout<<"Pleaae type the amount you want to convert"<<endl;
					cin>>amount;
					cin.ignore(20,'\n');


					if (amount>0)
					{
						cout<<"Your amount is " <<amount<<endl;


					}
				}	
				//Verifyig the Correct amount		


				cout<<endl;
				cout <<"Is"<<'\t'<< amount<<'\t'<<"the correct amount?(y/n) \n" ;
				cin>> type;
				cin.ignore(20,'\n');
				if (type=='Y'||type=='y')
				{
					cout<<"Great let's move on"<< endl;
				}	


				if (type=='n' ||type=='N')

				{
					cout<< "Ok, let's fix this!"<< endl;
					cout<<"Pleaae type the amount you want to convert  \n";
					cin>>amount;
					cin.ignore(20,'\n');
					if (amount>0)
					{
						cout<<"\t Your amount is " <<amount<<endl;
					}
				}




				// Conversion Interface
				cout<< "You have 2 options: "<<endl;
				cout<<"Option 1-Convert US dollars to CNY"<<endl;
				cout<<'\t'<<"And"<<endl;
				cout<<"Option 2-Convert CNY to US CNY "<<endl;


				cout<<endl;
				cout<<"Please type 1 or 2 :" <<endl;

				// Convertion 


				cin>>option;
				cin.ignore(20,'\n');
				if (option==1)
				{                  // For Option 1
					cout <<"You chose to convert US ->CNY!"<<endl;
					cout<< " Let me crunch some numbers...." << endl;
					cout<<".............................\n";
					cout<<".............................\n";
					cout<<".............................\n";
					cout<<".............................\n";
					US=amount*UStoCNY;
					cout<< "You have    "<<'\t' <<US<<"  US Dollars"<< endl;
					cout<< "Spend them well, otherwise your mom will be upset"<< endl;
				}

				if (option==2)
				{
					// For Option 2        
					cout <<"You chose to convert CNY->US!"<<endl;
					cout<<"Let me crunch some numbers...." << endl;
					cout<<".............................\n";
					cout<<".............................\n";
					cout<<".............................\n";
					cout<<".............................\n";
					CNY=amount*CNYtoUS;
					cout<< "You have    "<<'\t'<< CNY<< " CHYuan " << endl;
					cout << " Your mom wants you to buy some food and clothes!" << endl;

				}


				cout<<"Would you like to convert agian? (y/n)"<<endl;
				cin>> choice;                 

				cin.ignore(20,'\n');
			}
			while (choice=='y' || choice=='Y'); // Where the do-while loops ends


			cout<<" Goodbye!" <<endl;

			return 0;
		}




		// Choice 2 to convert CNY into bills denominations
		if (cType==2)
		{
			do{	


				cout<< "Please type the amount you want to convert into bills denominations : " <<endl;	
				cin>> amount;
				cin.ignore(20,'\n');
				while(amount<0) //  while loop for Choice 2 for entering positive numbers
				{
					cout<<"Please insert a positive number and letters not allowed:\n";
					cin>>amount;
					cin.ignore(20,'\n');
				}
				if (amount>0)
				{

					cout<< " Your amount is   " <<'\t'<< amount<<" CNY " << endl;

					cout<< " Let's convert that  amount "<<'\t' << amount << " into denominations" << endl;

					cout<< "You will need \n";
				}

				// Converter starts here
				if ( amount>=100)
				{
					bills100=(amount/100);
					amount=(amount-(100*bills100));

					if (100>0)
					{
						cout<<'\t'<<bills100<< " CNY 100 bill(s). "<<endl ;
					}
				}


				if (amount>=50)
				{ 
					bills50=(amount/50);
					amount=(amount-(50*bills50));

					if (bills50>0)
					{
						cout << '\t'<<bills50<< " CNY 50 bill(s). " <<endl;
					}
				}


				if (amount>=20)
				{
					bills20=(amount/20);
					amount=(amount-(20*bills20));

					if (bills20>0)
					{
						cout<<'\t'<< bills20<<" CNY 20 bill(s). " << endl;
					}
				}

				if ( amount>=10)
				{
					bills10=(amount/10);
					amount=(amount-(10*bills10));

					if (bills10>0)
					{
						cout<<'\t'<<bills10 << " CNY 10 bill(s). " <<endl;
					}
				}

				if (amount>=5)
				{
					bills5=(amount/5);
					amount=(amount-(5*bills5));

					if (bills5>0)
					{
						cout<<'\t'<<bills5 << " CNY 5 bill(s). " <<endl ;

					}
				}


				if (amount >=1)
				{
					bills1=(amount/1);
					amount=(amount-(1*bills1));


					if (bills1>0)
					{

						cout<<'\t' << bills1<< " CNY 1 bills(s). " <<endl;
					}
				}

				if (amount<1)
				{
					change=(amount*100);
					cout<<fixed<< setprecision(0) <<"Your change is ..." << change <<" CNY cent(s)" <<endl;

				}
				cout<<'\n';
				cout<<" Would you like to make another conversion? (y/n) "<< endl;
				cin>>choice;
				cin.ignore(20,'\n');
			}


			while (choice=='y' || choice=='Y');// while do loop that loops if the user want to make another conversion
			cout<<"Goodbye! " <<endl;
			return 0 ;
		}







		// Choice 3 to convert CNY bils to US currency
		if(cType=3)
		{
			do // Start of do-while loop for choice 3
			{	
				cout<< "Let's convert the CNY bills into US currency! "<< endl;
				cout<< "How many 100's CNY bills do you have? " << endl;
				cin>> bills100;
				cin.ignore(20,'\n');
				while(bills100<0)
				{			//while loop for entering positive numbers
					cout<< "How many 100's CNY bills do you have? " << endl;
					cin>> bills100;
					cin.ignore(20,'\n');
					if(bills100 >=0)
					{
						CNY100=bills100*100;

					}
				}
				cout<<"How many 50's CNY bills do have ?" << endl; 
				cin>>bills50;		
				cin.ignore(20,'\n');	
				while(bills50<0) //while loop for entering positive numbers
				{
					cout<<"How many 50's CNY bills do have ?" << endl;
					cout<<"Insert a positive num"<<endl;
					cin>>bills50;
					cin.ignore(20,'\n');
				}

				if(bills50 >=0)
				{
					CNY50=bills50*50;
					;
				}		
				cout<<"How many 20's CNY bills do you have ?" <<endl;

				cin>>bills20;
				cin.ignore(20,'\n');
				while (bills20<0) //while loop for entering positive numbers
				{	cout<<"Enter a positive num" <<endl;
					cout<<"How many 20's CNY bills do have ?" << endl;
					cin>>bills20;
					cin.ignore(20,'\n');
				}

				if(bills20 >=0)
				{
					CNY20=bills20*20;

				}


				cout<<"How many 10's CNY bills do you have?" << endl;
				cin>>bills10;
				while(bills10<0) //while loop for entering positive numbers
				{	cout<<"Enter a positive num" <<endl;
					cout<<"How many 10's CNY bills do have ?" << endl;
					cin>>bills10;
					cin.ignore(20,'\n');
				}
				if(bills10 >=0)
				{       
					CNY10=bills10*10;

				}
				cout<<"How many 5's CNY bills do you have? " <<endl;
				cin>>bills5;	
				cin.ignore(20,'\n');
				while(bills5<0)//while loop for entering positive numbers
				{	cout<<"Enter a positive num"<< endl;
					cout<<"How many 5's CNY bills do have ?" << endl;
					cin>>bills5;

				}		if(bills5 >=0)
				{       
					CNY5=bills5*5;

				}
				cout<<"How many 1's CNY bills do you have? "<<endl;
				while (bills1<0)//while loop for entering positive numbers
				{	cout<<"Enter a positive num" << endl;
					cout<<"How many 1's CNY bills do have ?" << endl;
					cin>>bills1;
					cin.ignore(20,'\n');
				}


				if(bills1 >=0)
				{       
					CNY1=bills20*20;

				}



				cout<<" Your total amount CNY is ..." <<endl;
				cout<<endl;
				cout<<" I am crunching numbers" <<endl;
				cout<<".............................\n";
				cout<<".............................\n";
				cout<<".............................\n";
				cout<<".............................\n";
				totalCNY=CNY100+CNY50+CNY20+CNY10+CNY5+CNY1;
				cout<< " You have " << '\t'<<totalCNY << " CNY " << endl;
				cout<<endl;
				cout<<" It will take me a second to convert it" << endl;
				totalUS=totalCNY*CNYtoUS;
				cout<<" Your CNY can be exchanged for \n ";
				cout << totalUS << " US " << endl;
				cout<<" Would you like to do it again (y/n) ? "<< endl;
				cin>>choice;
				cin.ignore(20,'\n');
			}

			while(choice=='y' || choice=='Y');	// do -while loops ends here
			cout<<" Goodbye ! " << endl;
			return 0;



		}	






	}




	return 0;



}








