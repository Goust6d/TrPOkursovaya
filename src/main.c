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
			if (A[i] == B[j])
			{
				cow++;
			}
		}
	}
	cow = cow - bull;
	printf("Num of bulls: %d     Num of cows: %d\n", bull, cow);
}

void game(int A[], int B[], short int n, int k)
{
	int q, kmax = 15;
	printf("Enter the number:\n\n");
	scanf("%i", &q);
	while ((q < 1000) || (q > 9999))
	{
		printf("Enter the number");
		scanf("%i", &q);
	}
	bender(n, q, B);
	cowandbull(A, B, n);
	while (bull != n)
	{
		printf("Wrong number! Try again!\n\n");
		scanf("%i", &q);
		k++;
		if (k == kmax)
		{
			printf("\nGame over!\n");
			system("pause");
			system("cls");
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
	system("cls");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	short int n = 4;
	int k;
	int A[4], B[4];
	Numgeneration(n, A);
	char c;

	while (c!=4)
	{
		printf("1. Start game.\n2. Hardmode (15 tryes)\n3. Rules\nX for Exit.\n");
		c = getchar();
		switch (c)
		{

			case '1':
			{
				system("cls");
				k = 20;
				game(A, B, n, k);
				break;
			}
			case '2':
			{
				system("cls");
				k = 1;
				game(A, B, n, k);
				break;
			}
			case '3':
			{
				system("cls");
				FILE *f = fopen("Rules.txt", "r");
				char ch;
				printf(" ");
				while (!feof(f))
				{
					ch = getc(f);
					if (ch == ' ')
					{
						k++;
					}
					if (k == 10)
					{
						printf("\n");
						k = 0;
					}
					printf("%c", ch);
				}
				printf("\n");
				fclose(f);
				system("pause");
				system("cls");
				break;
			}

			case 'x':
			{
				return 0;
			}
			default:
			{
				system("cls");
				printf("You choose wrong number. Please use keys 1-3 or ESC.\n");
				system("pause");
				system("cls");
			}
		}
	}
	system("PAUSE");
	return 0;

}
