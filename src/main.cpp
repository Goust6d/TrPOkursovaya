#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <conio.h>
#include <clocale>
#include <fstream>

using namespace std;

int  i = 0, cow, bull;

int Numgeneration(short int n, int A[])
{   
    srand(time(NULL));
    A[0] = rand() %9 + 1;
    	for (i = 1; i < n; i++)
        {
        	A[i] = rand() %10;      	
        }
		return(A[n]);
}

int bender(short int n, int q, int B[])
{
    int d = pow(10,n-1);
	for (i = 0; i < n; i++)
	{
		B[i] = q/d;
		q = q%d;
		d = d/10;
	}
	return(B[n]);
	
}

int CowAndBull(int A[], int B[], short int n)
{
	cow = bull = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if(A[i] == B[i])
		{
		bull++;
		}
	}
	
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(A[i] == B[j])
			cow++;
		}
	}
	cow = cow - bull; 
	cout<<"Num of bulls: " << bull << "  Num of cows: " << cow << endl;
	return(cow, bull);
}

void game(int A[], int B[], short int n, int k)
{
	int q, kmax=15;
	
	cout<<"Enter number:"<<endl;
    		cin>>q;
			while(q<1000 or q>9999)
			{
				cout<<"Enter number "<<endl;
				cin>>q;
			}
			bender(n, q, B);
 			CowAndBull(A, B, n);
			while (bull != n)
			{
				cout<<"Wrong number! Try again:"<<endl;
				cin>>q;
				k++;
				if (k==kmax)
				{
					cout << endl << "Game over!";
					system("pause");
					system("cls");
					break;
				}
				
				cout<<endl;
				bender(n, q, B);
	 		   	CowAndBull(A, B, n);
			}
}

int main()
{
	setlocale (LC_ALL, "Russian");
    short int n = 4;
    int A[n], B[n], q, t;
    Numgeneration(n, A);
    char ch_key, buff[300];
    bool bmenu = true;
    ifstream rules;

    
    while (bmenu) 
	{
		cout << "1. Start game.\n2. Rules\nESC for Exit.";
    	switch((ch_key=_getch()))
    	{
	
    	case '1': 
		{
			system("cls");
			cout << "1. Normal\n2. Hardmode (15 tryes)\n3. Back\n";
				switch ((ch_key=_getch()))
				{
					case '1':
					{
						system("cls");
						game(A, B, n, 20);
						break;
					}
					case '2':
					{
						system ("cls");
						game(A, B, n, 1);
						break;
					}
					case '3':
					{
						system ("cls");
						break;
					}
				}
			
			break;
		}
		
		case '2':
		{
			system ("cls");
			rules.open("Rules.txt");
			if (rules)
			{
				while (!rules.eof())
				{
					rules.getline(buff, 300);
					cout << buff << endl;
				}
			rules.close();
			}
			else cout << "Error";
			system("pause");
			system("cls");
			break;
			
		}
		
    	case 27: 
		{
			bmenu = false;
			cout << endl;
			break;
		}
		}
	}
    system("PAUSE");
    return 0;
}




