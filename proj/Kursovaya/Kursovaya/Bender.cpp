#include <cmath>
#include <stdlib.h>
#include <stdio.h>

int bender(short int n, int q, int B[])
{
	int d = pow(10,n-1);
	for (i = 0; i < n; i++)
	{
		B[i] = q/d;
		q = q%d;
		d = d/10;
	}
	
	if (r/1000 != B[0])
	{
		res = 0;
	}
	else res = 1;
	return(res, B[n]);
}
