/*
 * MemoryGame.c
 *
 * Created: 30-Apr-18 10:28:40 AM
 *  Author: patih
 */ 
#define F_CPU 10000000L
#include "iMemoryGame.h"
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#define F_CPU 10000000L
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "addition.h"
#include "subtraction.h"
#include "multiplication"
//#include "atmega2560_drivers.h"
#include <util/delay.h>
#include <time.h>


void startGame(){
		
	};
void endGame(){
	
	};
void roundWon(){
	
	};
void roundLost(){
	
	};
void delay()
	{	
	printf("PICKLE RIIIICK");	 
	_delay_ms(10000);
	};
	
int randomNumber(){
	int n = rand() % 7;
	printf("%d ", n);
	return n;
}
void randomSequence(memorygame_t *self){
	int *sequence = self -> sequence;
	int i;
	for (i= 0; i < (self ->level + 1); i++)
	{
		sequence[i] = randomNumber();
	}
	};
bool compareNumbers(int a,int b){
	if(a == b){
		return true;
	}
	return false;
	};
int convertValuefromPINBtoInt(int value){
	if(value == 0){
		PORTA = 254;
		_delay_ms(1000);
	}else if (value == 1)
	{
		PORTA = 253;
		_delay_ms(1000);
	}
	else if (value == 2)
	{
		PORTA = 251;
		_delay_ms(1000);
	}
	else if (value == 3)
	{
		PORTA = 247;
		_delay_ms(1000);
	}
	else if (value == 4)
	{
		PORTA = 239;
		_delay_ms(1000);
	}
	else if (value == 5)
	{
		PORTA = 223;
		_delay_ms(1000);
	}else if (value == 6)
	{
		PORTA = 191;
		_delay_ms(1000);
	}else if (value == 7)
	{
		PORTA = 127;
		_delay_ms(1000);
	}
	else{
		return -1;
	}
}
void readUserInput(){
	int n = PINB;
	while(PINB == 0xFF){
		n = convertValuefromPINBtoInt(n);
		printf("PINB %d", n);
		return n;
	}
	};
void randomLevels(){
	
	};