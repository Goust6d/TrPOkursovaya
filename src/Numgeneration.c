#include <time.h>
#include <stdlib.h>

int Numgeneration(short int n, int A[])
{
	srand(time(NULL));
	A[0] = rand()%9 + 1;
	int i, res = 0;
	for (i = 1; i < n; i++)
	{
		A[i] = rand()%10;
	}
	if( A[0] > 0)
	{
		res = 1;
	}
	else res = 0;
	return(res);
}

