#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>

using namespace std;

int  i = 0;

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
int main()
{
	short int n = 4;
    int A[n], B[n], q;
    Numgeneration(n, A);
    bender(n, q, B);
    system("PAUSE");
    return 0;
}




