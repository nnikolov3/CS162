# include<iostream>
# include<cctype>


using namespace std;

main()
{

	//Define a two dimensional array named temp of three rows and four columns of type int
	//such that the first row is initialized to 6,8,12,9;
	// the second row is initialized to 17,5,10,6
	// and the third row is initialized to 14,13,16,20

	//solution
	int temp[3][4]={{6,8,12,9},{7,5,10,6},{4,13,16,20}};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	for (j=0;j<100;j++)
		cin.get(list[j],16);

	for(j=0;j<100;j++)

		cout<<list[j]<<endl;

	bool again()
	{
		char response;
		cout << "Would you like to continue \n" ;
		cin>> response;
		cin.ignore(100,'\n');

		if (toupper(response)=='Y')

		{
			return true;
			else 
				return false;

		}


		int smalldiv(int n)
		{
			int count;
			count=2;
			while (count<n && n% count!=0)

			{
				count=count+1;

			}

			return (count);

		}

		int main()
		{

			int n;
			cout<<"Enter a natural number : \n" ;
			cin>> n;

			if (n==smalldiv(n))
			{
				cout<<n<<"is a prime number "<< endl;
			}
			else 
			{
				cout<<n<< "it is not a prime number "<<endl;

			}

			return 0;

		}


#include <iostream>
# include <fstream>
		// x*n=2x*(n/2) if n even
		//x*n=x+x*(n-1) if n odd



		int fastmult(int x,int y)

		{

			int result;
			result=0;

			while (y!=0)

			{

				if (y%2==0)

				{
					x=2*x;
					y=y/2;

				}

				else 
				{

					result =result+x;
					y=y-1;
				}

				return (result);

			}
		}

		int main()

		{
			int x,y;
			cout<<" Enter two natural numbers : " << endl;
			cin>>x>>y;
			cout<<x<<" * "<<y<<"="<<fastmult(x,y)<< endl;

			return 0;

		}
























