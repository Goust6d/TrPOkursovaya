#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
#include "func.h"

int  i = 0, cow, bull;

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
			if ((A[i] == B[j]) && (A[i] != A[j]))
			{
				cow++;
			}
		}
	}
	printf("Num of bulls: %d     Num of cows: %d\n", bull, cow);
}

void game(int A[], int B[], short int n, int k)
{
	int q, kmax = 30;
	while ((q < 1000) || (q > 9999))
	{
		printf("Enter the number: \n");
		scanf("%d", &q);
	}
	bender(n, q, B);
	cowandbull(A, B, n);
	while (bull != n)
	{
		printf("Wrong number! Try again!\n\n");
		q = 0;
		
		while ((q < 1000) || (q > 9999))
		{	
			printf("Enter the number: \n");
			scanf("%d", &q);
		}
		k++;
		if (k == kmax)
		{
			printf("\nGame over!\n");
			system("pause");
			break;
		}
		bender(n, q, B);
		cowandbull(A, B, n);
	}
	if (bull == n)
	{
		printf("You won! Congratulations!\n Back to main menu...");
	}
	system("pause");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	short int n = 4;
	int k;
	int A[n], B[n];
	Numgeneration(n, A);
	int c;

	while (c!=4)
	{
		printf("---[INFO]--- Use only 1-4 keys.\n\n1. Normal mode (30 tryes).\n2. Hardmode (15 tryes)\n3. Rules\n4. Exit.\n");
		//c = getchar(); 
		scanf("%d",&c);
		switch (c)
		{
			default:
			{
				printf("You choose wrong number. Please use keys 1-4.\n");
				system("pause");
				break;
			}
			case 1:
			{
				k = 1;
				printf("---[INFO]---\nUse only keys 0-9\n\n");
				game(A, B, n, k);
				Numgeneration(n, A);
				break;
			}
			case 2:
			{
				k = 15;
				printf("---[INFO]---\nUse only keys 0-9\n\n");
				game(A, B, n, k);
				Numgeneration(n, A);
				break;
			}
			case 3:
			{
			/*	FILE *f;
				char str[400];
				char *estr;
				f = fopen("/TrPOkursovaya/src/Rules.txt", "r");
				if (f == NULL)
				{
					printf("Error\n");
					break;
				}
				while (1)
				{
					estr = fgets (str, sizeof(str), f);
					if (estr == NULL)
					{
						if (feof(f)!=0)
						{
							break;
						}
					}
					printf ("    %s", str);
				}
				if (fclose(f) == EOF)
				{
					printf("Error\n");
				}
				printf("\n");
				break;*/
				printf("The rules of the game Bulls and Cows\n\n");
				printf("A certain number is guessed. You must guess it by typing with the keyboard.\n");
				printf("When you enter a number you will be shown the number of Bulls and Cows in the number.\n");
				printf("The number of Bulls is the number of digits that have coincided numerically and in the order of the place, in the number and number entered.\n");
				printf("If the figure does not stand on this place, but it is present in the number conceived, then this figure is considered to be Cow.\n");
				printf("In normal mode, you have 30 attempts.\n");
				printf("In a complicated mode, the number of your attempts is limited to 15, so decide carefully. :-)\n\n");
				break;
			}

			case 4:
			{
				return 0;
			}
		}
	}
	system("pause");
	return 0;
}
