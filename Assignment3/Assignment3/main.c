/*
 * Assignment3.c
 *
 * Created: 4/17/2018 10:29:35
 * Author : Patrick 
 */ 

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



//void nextLevel(int level);

int main(void)
{
	DDRA = 0xff;
	//int level = 1;
		
	for (int i = 1; i < 3; i++)
	{
		uint8_t state = PINB;
		if(PINB == 0b11111111){
		nextLevel(i);
		PORTA = 0b11111111;
		_delay_ms(1000);
		}
		else(PINB==0b11111110){
			break;
		}
	}
}

void nextLevel(int level)
{
	
	if (level == 1)
	{
		PORTA = 0b11111101;
		_delay_ms(1000);
	}
	else if(level == 2)
	{
		PORTA = 0b11111101;
		_delay_ms(1000);
		PORTA = 0b01111111;
		_delay_ms(1000);
	}
}
