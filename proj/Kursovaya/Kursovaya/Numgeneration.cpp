#include <ctime>
#include <stdlib.h>
#include <cmath>

int Numgeneration(short int n, int A[])
{
	srand(time(NULL));
	st = pow(10,n-1);
	A[0] = rand() %9 + 1;
	for (int i = 1; i < n; i++)
		{
		A[i] = rand() %10;      	
		}
        int k = pow(10, n - 1);
	for (i = 0; i < n; i++)
		{
		sum += A[i] * k;
		k/=10;
		}   
	if(( sum > 999) && ( sum < 10000)) 
	{
		res = 1;
	}
	else 
	res = 0;
	return(res, A[n]);
}
