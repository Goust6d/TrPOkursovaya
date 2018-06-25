#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <conio.h>

void CowAndBull(int A[], int B[], short int n, q, b)
{
	int d = pow(10,n-1);
	for (int i = 0; i < n; i++)
	{
		B[i] = q/d;
		q = q%d;
		d = d/10;
	}
	
	int d = pow(10,n-1);
	for (i = 0; i < n; i++)
	{
		A[i] = b/d;
		b = b%d;
		d = d/10;
	}
	
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
	If((bull = 2)&&(cow = 1)){
		res = 1;
	}
	else res 0;
	return(res);
}
