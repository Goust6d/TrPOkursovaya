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

int main()
{
	short int n = 4;
    int A[n], B[n], q;
    Numgeneration(n, A);
    system("PAUSE");
    return 0;
}




