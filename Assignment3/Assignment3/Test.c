/*
 * CFile1.c
 *
 * Created: 01-May-18 9:19:26 AM
 *  Author: Zahata97
 */ 


#include "Test.h"

int tests_run = 0;

static char * check_Test(){
	int num = 5;
	int num1 = 5;
	int result = check(num,num1);
	mu_assert("result !=1",result ==1);
	return 0;
}

static char * all_tests(){
	mu_run_test(check_Test);
	return 0;
}

 int mainTest()
 {
	 init_stdio(0, 10000000L);
	 sei();
	 
	 DDRA = 0Xff;
	 
	 char *result = all_tests();
	 if (result != 0) {
		 printf("error: %s\n", result);
	 }
	 else {
		 printf("ALL TESTS PASSED\n");
	 }
	 
	 printf("Tests run: %d\n", tests_run);
	 
	 while(1);
	 return result != 0;
 }



