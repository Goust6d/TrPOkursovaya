#define CTEST_MAIN

#include <stdlib.h>
#include <stdio.h>
#include <func.h>
#include <ctest.h>
#include <time.h>

CTEST(Numgeneration, correct_Numgeneration){
	srand(time(NULL));
	short int n = 4;
	int A[4];
	int result = Numgeneration(n, A);
	int expect = 1;
	ASSERT_EQUAL(expect, result);
}


CTEST(bender, correct_bender){
	short int n = 4;
	int B[4], q = 1111;
	int result = bender(n, q, B);
	int expect = 1;
	ASSERT_EQUAL(expect, result);
}

CTEST(Bender, uncorrect_Bender){
	short int n = 4;
	int B[5], q = 11111;
	int result = bender(n, q, B);
	int expect = 0;
	ASSERT_EQUAL(expect, result);
}

int main(int argc, const char** argv)  
{
	int test_res = ctest_main(argc, argv);
	return test_res;
}
