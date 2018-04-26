/*
 * Assignment3.c
 *
 * Created: 4/17/2018 10:29:35
 * Author : Patrik
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include "atmega2560_drivers.h"

init_stdio(0, 10000000L);

void nextLevel(int level);

int main(void)
{
	DDRA = 0xff;
	//int level = 1;
	
	for (int i = 1; i < 3; i++)
	{
		if()
		{
		nextLevel(i);
		PORTA = 0b11111111;
		_delay_ms(1000);
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
