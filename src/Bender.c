#include <stdlib.h>
#include <stdio.h>
#include "func.h"
int bender(short int n, int q, int B[])
{
	int i = 0, j = 0, res = 0, d = 1;
	for (j = 0; j < n - 1; j++)
	{
		d = d* 10;
	}
	for ( i = 0; i < n; i++)
	{
		B[i] = q/d;
		q = q%d;
		d = d/10;
	}
	
	if (B[0] < 10 )
	{
		res = 1;
	}
	else res = 0;
	return(res);
}
