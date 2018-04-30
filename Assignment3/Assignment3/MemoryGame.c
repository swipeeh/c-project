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
	if(value == 254){
		return 0;
		_delay_ms(1000);
	}else if (value == 253)
	{
		return 1;
		_delay_ms(1000);
	}
	else if (value == 251)
	{
		return 2;
		_delay_ms(1000);
	}
	else if (value == 247)
	{
		return 3;
		_delay_ms(1000);
	}
	else if (value == 239)
	{
		return 4;
		_delay_ms(1000);
	}
	else if (value == 223)
	{
		return 5;
		_delay_ms(1000);
	}else if (value == 191)
	{
		return 6;
		_delay_ms(1000);
	}else if (value == 127)
	{
		return 7;
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