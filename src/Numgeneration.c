#include <time.h>
#include <stdlib.h>

int Numgeneration(short int n, int A[])
{
	srand(time(NULL));
	A[0] = rand() % 9 + 1;
	int i, res = 0, j, f = 0;
	i = 1;
	while (i < 4)
		{
			A[i] = rand() % 10;
			for (j = 0; j < i; j++)
			{
				if (A[i] == A[j])
				{
					f = 1;
					break;
				}
			}
			if (f == 0)
			{
				i++;
			}
			f = 0;
		}
	if( A[0] < 10)
	{
		res = 1;
	}
	else res = 0;
	return(res);
}
