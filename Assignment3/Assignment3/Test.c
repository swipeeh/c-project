/*
 * CFile1.c
 *
 * Created: 01-May-18 9:19:26 AM
 *  Author: Zahata97
 */ 


#include "Test.h"

int tests_run = 0;

static char * win_Test(){
	DDRA = 0xff;
	PORTA = 0b10101010;
	mu_assert("error,win() != 0b10101010" , PORTA == 0b10101010);
	return 0;
}

static char * all_tests(){
	mu_run_test(win_Test());
	return 0;
}

 int main()
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



