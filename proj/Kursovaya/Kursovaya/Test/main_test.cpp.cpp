#include <stdlib.h>
#include <stdio.h>
#include <ctest.h>
#include <time.h>

CTEST(Numgeneration, correct_Numgeneration){
	srand(time(NULL));
	short int n = 4;
	int A[n];
	int result = Numgeneration(n, A);
	int expect = 1;
	ASSERT_EQUAL(expect, result)
}

CTEST(Numgeneration, uncorrect_Numgeneration){
	srand(time(NULL));
	short int n = 5;
	int A[n];
	int result = Numgeneration(n, A);
	int expect = 0;
	ASSERT_EQUAL(expect, result)
}

CTEST(Bender, correct_Bender){
	short int n = 4;
	int B[n], q = 1111;
	int result = Bender(n, q, B);
	int expect = 1;
	ASSERT_EQUAL(expect, result)
}

CTEST(Bender, uncorrect_Bender){
	short int n = 5;
	int B[n], q = 11111;
	int result = Bender(n, q, B);
	int expect = 0;
	ASSERT_EQUAL(expect, result)
}

CTEST(CowandBull, correct_CowandBull){
	short int n = 4;
    int A[n], B[n], q = 1000, b =7100;
    int result = CowandBull(A, B, n, q, b);
	int expect = 1;
	ASSERT_EQUAL(expect, result)
}

CTEST(CowandBull, uncorrect_CowandBull){
	short int n = 4;
    int A[n], B[n], q = 1000, b =9999;
    int result = CowandBull(A, B, n, q, b);
	int expect = 0;
	ASSERT_EQUAL(expect, result)
}

int main(int argc, const char** argv)  {
    int test_res = ctest_main(argc, argv);
return test_res;
