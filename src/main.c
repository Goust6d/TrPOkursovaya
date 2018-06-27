#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
// #include <cmath>
#include <locale.h>
// #include <fstream>
#include "func.h"

//using namespace std;
int  i = 0, cow, bull;

int numgeneration(short int n, int A[])
{
	srand(time(NULL));
	A[0] = rand() % 9 + 1;
	for (i = 1; i < n; i++)
	{
		A[i] = rand() % 10;
	}
	return(A[n]);
}

int Bender(short int n, int q, int B[])
{
	int d = 1000;
	for (i = 0; i < n; i++)
	{
		B[i] = q / d;
		q = q % d;
		d = d / 10;
	}
	return(B[n]);

}

void cowandbull(int A[], int B[], short int n)
{
	cow = bull = 0;
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		if (A[i] == B[i])
		{
			bull++;
		}
	}

	for (i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (A[i] == B[j])
			{
				cow++;
			}
		}
	}
	cow = cow - bull;
	printf("Num of bulls: %d     Num of cows: %d", bull, cow);
	// cout << "Num of bulls: " << bull << "  Num of cows: " << cow << endl;
}

void game(int A[], int B[], short int n, int k)
{
	int q, kmax = 15;

	printf("Enter the number");
	scanf("%i", &q);
	// cout << "Enter number:" << endl;
	// cin >> q;
	while ((q < 1000) || (q > 9999))
	{
		printf("Enter the number");
		scanf("%i", &q);
		// cout << "Enter number: " << endl;
		// cin >> q;
	}
	Bender(n, q, B);
	cowandbull(A, B, n);
	while (bull != n)
	{
		printf("Wrong number! Try again!\n");
		scanf("%i", &q);
		// cout << "Wrong number! Try again:" << endl;
		// cin >> q;
		k++;
		if (k == kmax)
		{
			printf("\nGame over!\n");
			// cout << endl << "Game over!";
			system("pause");
			system("cls");
			break;
		}

		//cout << endl;
		Bender(n, q, B);
		cowandbull(A, B, n);
	}
	//cout << endl;
	if (bull == n)
	{
		printf("You won! Congratulations!\n Back to main menu...");
		// cout << "You won! Congratulations!\n Back to main menu...";
	}
	system("pause");
	system("cls");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	short int n = 4;
	int k;
	int A[4], B[4];
	//numgeneration(n, A);
	char ch_key, c; //buff[300];
	bool bmenu = true;
//	ifstream rules;


	while (bmenu)
	{
		c = getchar();
		printf("1. Start game.\n2. Rules\nESC for Exit.");
		// cout << "1. Start game.\n2. Rules\nESC for Exit.";
		switch (c)
		{

			case '1':
			{
				ch_key = getchar();
				system("cls");
				printf("N. Normal\nH. Hardmode (15 tryes)\n3. Back\n");
				// cout << "1. Normal\n2. Hardmode (15 tryes)\n3. Back\n"
				switch (ch_key);
				{
					case 'n':
					{
						system("cls");
						k = 20;
						game(A, B, n, k);
						break;
					}
					case 'h':
					{
						system("cls");
						k = 1;
						game(A, B, n, k);
						break;
					}
					case '3':
					{
						system("cls");
						break;
					}
					/*default:
					{
						system("cls");
						printf("You choose wrong number. Please use keys 1-3 or ESC.\n");
						// cout << "You choose wrong number. Please use keys 1-3 or ESC.\n";
						system("pause");
						system("cls");
					}*/
				}
				break;
			}

			/*case '2':
			{
				system("cls");
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
				else printf("Error");
				system("pause");
				system("cls");
				break;
			}*/

			case 27:
			{
				bmenu = false;
				//cout << endl;
				break;
			}
			default:
			{
				system("cls");
				printf("You choose wrong number. Please use keys 1-3 or ESC.\n");
				// cout << "You choose wrong number. Please use keys 1-3 or ESC.\n";
				system("pause");
				system("cls");
			}
		}
	}
	system("PAUSE");
	return 0;

}
